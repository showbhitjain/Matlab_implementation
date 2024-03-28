clc; clear all;

mdhparams = [
    0       0       0.333   0;
    0       -pi/2   0       0;
    0       pi/2    0.316   0;
    0.0825  pi/2    0       0;
   -0.0825 -pi/2    0.384   0;
    0       pi/2    0       0;
    0.088   pi/2    0.107   0
];

dhparams = [
    0,      -pi/2,    0.333,  0;
    0,       pi/2,    0,      0;
    0.0825,  pi/2,    0.316,  0;
   -0.0825, -pi/2,    0,      0;
    0,       pi/2,    0.384,  0;
    0.088,   pi/2,    0,      0;
    0.0003,   0,    0.107,  0];

jointMinValues = [-2.8973, -1.7628, -2.8973, -3.0718, -2.8973, 0.6500, -2.8973];
jointMaxValues = [2.8973, 1.7628, 2.8973, -0.0698, 2.8973, 3.7525, 2.8973];

jointvelMinValues = [-2.1750 -2.1750 -2.1750 -2.1750 -2.6100 -2.6100 -2.6100];
jointvelMaxValues = [2.1750 2.1750 2.1750 2.1750 2.6100 2.6100 2.6100];
Homejointpositions = [0 ,0, 0, -pi/2, 0, pi/2, pi/4];

frankarobot  = loadrobot("frankaEmikaPanda");
show(frankarobot)
body_Tcp_2 = rigidBody('Gripper_TCP');
joint_Tcp_2 = rigidBodyJoint('Gripper_TCP_frame', 'fixed');
tform_tcp_2 = trvec2tform([0 0 0.103399])*eul2tform([-pi/4 0 0]);
setFixedTransform(joint_Tcp_2,tform_tcp_2);
body_Tcp_2.Joint = joint_Tcp_2;
addBody(frankarobot,body_Tcp_2,'panda_link8');

%Set initial joint position

 Initalconfig = frankarobot.homeConfiguration;
% 
 for i = 1:7
      Initalconfig(i).JointPosition = Homejointpositions(i);
 end
% 
% % Set the modified home configuration back to the robot
% show(frankarobot, Initalconfig, ); % show function does not support code generation
%  interactiveGUI = interactiveRigidBodyTree(frankarobot);


% cd ~/MATLAB/<version>
 
%Set End effector name + set TcP at Gripper
%BUild robot from DH Parameters  [a alpha d theta] MOdiefied DH
%Create a rigid body tree. This tree is initialized with a base coordinate frame to attach bodies to.
frankarobot_mdh = rigidBodyTree(MaxNumBodies= 9,DataFormat="row");
body1 =rigidBody('Franka_link1');
jnt1 = rigidBodyJoint('Franka_joint1','revolute');
jnt1.HomePosition = 0;
jnt1.PositionLimits = [jointMinValues(1), jointMaxValues(1)];
setFixedTransform(jnt1,mdhparams(1,:),'mdh');
body1.Joint = jnt1;

%Add the first body to the tree. 
% Specify that you are attaching it to the base of the tree. 
% The fixed transform defined previously is from the base (parent) to the first body.
addBody(frankarobot_mdh,body1,'base')

% Dynamically create and add the rest of the bodies
for i = 2:7
    bodyName = ['Franka_link', num2str(i)];
    jointName = ['Franka_joint', num2str(i)];
    body = rigidBody(bodyName);
    joint = rigidBodyJoint(jointName, 'revolute');
    joint.HomePosition = Homejointpositions(i);
    joint.PositionLimits = [jointMinValues(i), jointMaxValues(i)];
    setFixedTransform(joint, mdhparams(i,:), 'mdh');
    body.Joint = joint;
    addBody(frankarobot_mdh, body, ['Franka_link', num2str(i-1)]);
end

body_Tcp = rigidBody('Gripper_TCP');
joint_Tcp = rigidBodyJoint('Gripper_TCP_frame', 'fixed');
tform_tcp = trvec2tform([0 0 0.103399])*eul2tform([-pi/4 0 0]);
setFixedTransform(joint_Tcp,tform_tcp);
body_Tcp.Joint = joint_Tcp;
addBody(frankarobot_mdh,body_Tcp,'Franka_link7');

%getTransform(frankarobot,Initalconfig,'panda_link8','panda_link0');
Initalconfig_mdh = frankarobot_mdh.homeConfiguration;

% for i = 1:
%     Initalconfig_mdh(i).JointPosition = Homejointpositions(i);
% end
getTransform(frankarobot_mdh,frankarobot_mdh.homeConfiguration,'Franka_link7','base');

Starting_tcp_tform = getTransform(frankarobot_mdh,frankarobot_mdh.homeConfiguration,'Gripper_TCP','base');
toolPositionHome = Starting_tcp_tform(1:3,4);

%showdetails(frankarobot_mdh); %showdetails function does not support code generation
Jacobi_MATRIX = jacobian_cartesian(frankarobot_mdh,[0,0,0,-1.570796326794897,0,1.570796326794897,0.785398163397448],8)

% Maximum number of waypoints (for Simulink)
maxWaypoints = 20;

% Positions (X Y Z)
% Define waypoints
waypoints = [toolPositionHome'; 
             toolPositionHome' + [0, 0.1 , 0]; 
             toolPositionHome' + [0, 0.1, -0.1]; 
             toolPositionHome' + [0, -0.1, -0.1]; 
             toolPositionHome'];

% waypoints = [toolPositionHome'; 
%              toolPositionHome' + [0, 0 , 0]; 
%              toolPositionHome' + [0, 0, 0]; 
%              toolPositionHome' + [0, -0, 0]; 
%              toolPositionHome'];
% + [0, 0, 0.2]
% Ensure waypoints are transposed correctly for vertical concatenation
waypoints = waypoints';
         
% Euler Angles (Z Y X) relative to the home orientation       
% orientations = [0     0    pi;
%                 0  0    3*pi/4; 
%                 0   0  pi/2;
%                 0   0    3*pi/4;
%                 0   0    pi]';   

     orientations = [0     0    pi;
                0  0    pi; 
                0   0  pi;
                0   0    pi;
                0   0    pi]';          
% Array of waypoint times
waypointTimes = 0:4:16;

% Trajectory sample time
ts = 0.001; %10 ms
trajTimes = 0:ts:waypointTimes(end);

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
% Acceleration (quintic only)
waypointAccels = zeros(size(waypointVels));

% Acceleration times (trapezoidal only)
waypointAccelTimes = diff(waypointTimes)/4;

% Set up plot
plotMode = 2; % 0 = None, 1 = Trajectory, 2 = Coordinate Frames
show(frankarobot,Initalconfig,'Frames','off','PreservePlot',false);
xlim([-1 1]), ylim([-1 1]), zlim([0 1.2])
hold on
if plotMode == 1
    hTraj = plot3(waypoints(1,1),waypoints(2,1),waypoints(3,1),'b.-');
end
plot3(waypoints(1,:),waypoints(2,:),waypoints(3,:),'ro','LineWidth',2);

%% Generate and follow trajectory
% Loop through segments one at a time
trajType = 'trap';
numWaypoints = size(waypoints,2);
for w = 1:numWaypoints-1
        
    
    
    
    
    
    % Get the initial and final transforms and times for the segment
    T0 = trvec2tform(waypoints(:,w)') * eul2tform(orientations(:,w)');
    Tf = trvec2tform(waypoints(:,w+1)') * eul2tform(orientations(:,w+1)');
    timeInterval = waypointTimes(w:w+1);
    trajTimes = timeInterval(1):ts:timeInterval(2);
    
    % Generate time scaling trajectory for the segment on the range [0 1]
    switch trajType
        case 'trap'
            [s,sd,sdd] = trapveltraj([0 1],numel(trajTimes), ... 
                                     'EndTime',diff(timeInterval));
        case 'cubic'
            [s,sd,sdd] = cubicpolytraj([0 1],timeInterval,trajTimes);
        case 'quintic'
            [s,sd,sdd] = quinticpolytraj([0 1],timeInterval,trajTimes);
        otherwise
            error('Invalid trajectory type! Use ''trap'', ''cubic'', or ''quintic''');
    end
    
    % Find the transforms from trajectory generation
    [T,vel,acc] = transformtraj(T0,Tf,timeInterval,trajTimes, ... 
                                'TimeScaling',[s;sd;sdd]);  
       
    % Trajectory visualization for the segment
    if plotMode == 1
        eePos = tform2trvec(T);
        set(hTraj,'xdata',eePos(:,1),'ydata',eePos(:,2),'zdata',eePos(:,3));
    elseif plotMode == 2
        plotTransforms(tform2trvec(T),tform2quat(T),'FrameSize',0.05)
    end
end



    % eeOffset = 0.12;
    % eeBody = robotics.RigidBody('end_effector');
    % eeBody.Mass = 0;
    % eeBody.Inertia = [0 0 0 0 0 0];
    % setFixedTransform(eeBody.Joint,trvec2tform([eeOffset 0 0]));
    % addBody(robot,eeBody,'link5');

   
    %interactiveGUI.Configuration = randomConfiguration(gen3);
    %addConfiguration(interactiveGUI)
%disp(interactiveGUI.StoredConfigurations)