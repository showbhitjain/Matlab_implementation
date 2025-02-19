clear; close all;

import_robot_panda; 
clear obstacle_avoidance_equation;

%Setting up of Trajectory Waypoints
Starting_tcp_tform = getTransform(robot,robot.homeConfiguration,'Gripper_TCP','base');
toolPositionHome = Starting_tcp_tform(1:3,4);

% Define waypoints

% waypoints = [toolPositionHome + [0; 0; 0], [
 
% toolPositionHome + [0; 0.3; 0.1], ...
%  toolPositionHome + [0; 0.3; -0.2], ...
% toolPositionHome + [0; -0.3; -0.2], ...
% toolPositionHome + [-0.3; -0.3; -0.2]];
% 
% waypoints = [toolPositionHome'; 
%              toolPositionHome' + [0, 0.2 , 0]; 
%              toolPositionHome' + [0, 0.2, -0.2]; 
%              toolPositionHome' + [0, -0.3, -0.2]; 
%              toolPositionHome' + [-0.3 -0.3 -0.2]]';
    waypoints = [[ 0.5545, 0.5545, 0.5545,  0.15];
    [ 0.2000, 0.2000,-0.4, 0.3];
    [ 0.2211, 0, 0,  0]];



%  toolPositionHome' + [0, 0.3 , 0.1]; second waypoint
% waypoints = [toolPositionHome'; 
%              toolPositionHome' + [0, 0 , 0]; 
%              toolPositionHome' + [0, 0, 0]; 
%              toolPositionHome' + [0, -0, 0]; 
%              toolPositionHome']';
% + [0, 0, 0.2]
% Ensure waypoints are transposed correctly for vertical concatenation

         
final_position_TCP = waypoints(:,end);
% Euler Angles (Z Y X) relative to the home orientation       

  % [ 0,        0.3827,    0.7071,    0.3827,     0],
  %   [1.0000,    0.9239,    0.7071,    0.9239,    1.0000],
  %   [ 0,         0,         0,         0,         0],
  %   [ 0,         0,         0,         0,         0]

% orientations = [0     0    pi;
%                 0  0    3*pi/4; 
%                 0   0  pi/2;
%                 0   0    3*pi/4;
%                 0   0    pi]';   

orientations = [0.0000    1.0000         0         0;
                0.0000    1.0000         0         0;
                0.0000    1.0000         0         0;
                0.0000    1.0000         0         0;
                0.0000    1.0000         0         0]';

orientations = [
    [0,         0,        0,          0];
    [1,          1,        1,         1];
    [0,         0,         0,         0];
    [0,         0,         0,         0]
  ];
     % % 
     % orientations = [0     0    pi;
     %                0  0    pi; 
     %                0   0  pi;
     %                0   0    pi;
     %                0   0    pi]';          

     
 
     % Array of waypoint times
waypointTimes = [0, 4, 10, 16];
%waypointTimes = 0:3:12;
% Trajectory sample time
ts = 0.001; %1 ms


%% Additional parameters

% Boundary conditions (for polynomial trajectories)
% Velocity (cubic and quintic)
% waypointVels = 0.1 *[ 0  1  0;
%                      -1  0  0;
%                       0 -1  0;
%                       1  0  0;
%                       0  1  0]';
waypointVels = 0.1 *[ 0  0  0;
                     0  0  0;
                      0 0  0;
                      0  0  0;
                      0  0  0]';

waypointVels = [
    [0,0,0,0];
    [0,0,0,0];
    [0,0,0,0]
  ];
% Acceleration (quintic only)
waypointAccels = zeros(size(waypointVels));

% Acceleration times (trapezoidal only)
waypointAccelTimes = 0.25 * diff(waypointTimes);
trajType = 'cubic'; % Trajectory type
trajTimes = 0:ts:waypointTimes(end);


%From Here onwards the process starts 
%Trajectory Generation using trajectory waypoints 
% Cartesian Motion only
% Call the trajectory generation function
[xd, xd_vel, xdd] = positionTrajectory(waypoints, waypointTimes, ts, trajType, waypointVels, waypointAccels);

[desired_quaternions,desired_angular_velocity,desired_angular_accel] = orientationTrajectory(orientations,waypointTimes,ts,trajType);

config = struct();
config.useObjectiveNormInfinity = false;  % Use infinity norm term
config.weightNormInfinity = 0.1;         % Weight for objective 1

config.useObjectiveNormL2 = true;  % Use two-norm term
config.weightNormL2 = 1;         % Weight for objective 2

config.useObjectiveTrajectoryFollowing = false; % Use norm of (jacobi*q_vel - xd_eff_vel)
config.weightTrajectoryFollowing = 2;         % Weight for objective 3

config.useObjectiveJointAcceleration = false;  % Use sum of (q_vel - q_vel_previous)^2
config.weightJointAcceleration = 2;         % Weight for objective 4

config.useObjectiveManipulability = true ; %use of manipulability constraint for Jm' * q_velocity
config.weightManipulability = 0.1;         % singularity avoidance and manipulability maximization

% Constraint configuration
config.applyEqualityConstraints = true;    % Flag to apply equality constraints
config.applyInequalityConstraints = true;  % Flag to apply inequality constraints

%Slack 
config.applySlack = true;
config.Slacklowerbound = [-0.25,-0.25,-0.25,-deg2rad(2),-deg2rad(2),-deg2rad(60)]';
config.Slackupperbound = [0.25,0.25,0.25,deg2rad(2),deg2rad(2),deg2rad(60)]';
config.SlackPenaltyWeight = [1 1 1 1 1 0.5];
config.SlackObjectiveWeight = 20;
%Choose either Obstacle avoidance scheme 1 or 2 otherwise it would result in error;


%Obstacle avoidance scheme
config.obstacleAvoidanceScheme = true; %Flag to apply obstacle avoidance scheme
config.k = 2 ; %The efficiency of the manipulator to change the velocity of
% the critical point C when avoiding obstacles increases with the for
% obstacle avoidance scheme 2 
% decrease of k, but the burden of the manipulator will increase
% at the same time.

config.gamma = 2; %gamma defines the joint limit avoidance gain Increasing gamma: 
%This means the joint can move faster since the velocity limits are less restrictive.
% However, it also means that the joint is more prone to reach its physical limits faster, 
% potentially leading to more abrupt stops or higher dynamic stresses.

%{
Decreasing gamma: Conversely, decreasing χ reduces the product gamma*(θ+  − θ) and gamma*(θ−  − θ), 
which narrows the range between the upper and lower velocity bounds. 
This constrains the joint to slower velocities, potentially increasing precision and safety.
However, it may also limit the responsiveness or speed of the system's movements.
%}

config.dynamicSlack = true;
config.applyVelocityDamper = true;

config.jointLimitActivationDistance = 10; % in degrees
config.jointLimitStopDistance = 3;
config.jointLimitGain = 1;

joint_velocity = zeros(number_of_joints, numel(trajTimes));
joint_vector = zeros(number_of_joints, numel(trajTimes));


desired_joint_velocity = zeros(number_of_joints, numel(trajTimes));

desired_joint_vector = zeros(number_of_joints, numel(trajTimes));

joint_vector(:,1) = Homejointpositions';
desired_joint_vector(:,1)  = Homejointpositions';
Kp = diag([1 1 1]);
Ko = diag([1 1 1]);

% Use an enum or integer to represent the obstacle type for efficiency
OBSTACLE_SPHERE = 1;
OBSTACLE_CYLINDER = 2;
OBSTACLE_BOX = 3;


obstacle_sphere_1 = struct(...
    'type', OBSTACLE_SPHERE, ...               
    'center', toolPositionHome' + [0, 0.2 , 0], ...
    'dimensions', [0.04, 0.04, 0.04], ... 
    'orientation', [1, 0, 0, 0], ... 
    'axis', 0 ...        
);
%center_1 [0.30, 0.20, 0.8]
obstacle_sphere_2 = struct(...
    'type', OBSTACLE_SPHERE, ...               
    'center', [0.5545, 0.20, 0.3211], ...
    'dimensions', [0.05, 0.05, 0.05], ... 
    'orientation', NaN, ... 
    'axis', NaN ...        
);
% obstacle_sphere_3 = struct('type', OBSTACLE_SPHERE, 'center', ...
%     [0.4, 0.15, 0.7], 'dimensions', [0.03, 0.03, 0.03], 'orientation', NaN, 'axis', NaN);
obstacles = [obstacle_sphere_1 obstacle_sphere_2];
%obstacle_bus  =Simulink.Bus.createObject(obstacles);

%radius for each link
radius_of_links = [0.1 0.1 0.1 0.1 0.1 0.1 0.1];
d_influence = 0.04;
d_stop = 0.01;


clear integrate_velocity
%joint_velocity for obsacle avoidance at t = 0
joint_velocity_obstacle_avoidance = zeros(number_of_joints,1); 

% Open the log file before the loop starts
%logFile = fopen('obstacle_avoidance_log.txt', 'a');
mindistance = zeros(1,numel(trajTimes)-1) ;
translational_error = zeros(3,numel(trajTimes)-1) ;
rotational_error = zeros(3,numel(trajTimes)-1) ;

jointMinValues = jointMinValues' ;
jointMaxValues = jointMaxValues' ;
jointvelMinValues = jointvelMinValues' ; 
jointvelMaxValues = jointvelMaxValues' ; 


sphere_Center = [0.5545,0.20,0.5211];
sphere_Radius = 0.08;
linesegments = createLineSegments(mdhparams,robot,radius_of_links,Homejointpositions);
[s,dist,closestPointLink,closesePointObstacle]  = calculate_distance_lss_pss(linesegments(7).aSegmentV0,linesegments(7).aSegmentV1,radius_of_links(1),sphere_Center,sphere_Radius);

 transform = getTransform(robot,Homejointpositions,'base','robot_link6');
closestPointLinkNew = [(closestPointLink)';1];
relativeLinkNewHom = transform * closestPointLinkNew ;
relativeLinkPoint = relativeLinkNewHom(1:3)';
addCriticalPoint(robot,'relativeBody','relativeJOINT',relativeLinkPoint,7);

transformRelative = getTransform(robot,Homejointpositions,'relativeBody','base');
 JacobiRelative = rearrangejacobi(geometricJacobian(robot,Homejointpositions,'relativeBody'),7);

joint_vector_visualisation = readmatrix('/home/shobhit/tum_sj_obstacleavoidancelib/outputDesiredJointsDemoPartTwo.csv');
trajTimes = 0:0.001:16;

number_of_joints = 7;
joint_vector_visualization = zeros(numel(trajTimes),9);
joint_vector_visualization(:,1:number_of_joints) = joint_vector_visualisation';
% optimizedVisualizeRobot_2('frankarobot',joint_vector_visualization,waypoints,2,obstacles);
optimizedVisualizeRobot_2('frankarobot',joint_vector_visualization,waypoints,2,[]);

