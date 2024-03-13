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
Homejointpositions = [0 ,0, 0, -pi/2, 0, pi/2, pi/4];

frankarobot  = loadrobot("frankaEmikaPanda");
show(frankarobot);

%Set initial joint position

Initalconfig = frankarobot.homeConfiguration;

for i = 1:7
    Initalconfig(i).JointPosition = Homejointpositions(i);
end

% Set the modified home configuration back to the robot
show(frankarobot, Initalconfig); % show function does not support code generation
 interactiveGUI = interactiveRigidBodyTree(frankarobot);



 
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
tform_tcp = trvec2tform([0.103399 0 0])*eul2tform([-pi/4 0 0]);
setFixedTransform(joint_Tcp,tform_tcp);
body_Tcp.Joint = joint_Tcp;
addBody(frankarobot_mdh,body_Tcp,'Franka_link7');

getTransform(frankarobot,Initalconfig,'panda_link8','panda_link0');
Initalconfig_mdh = frankarobot_mdh.homeConfiguration;

% for i = 1:7
%     Initalconfig_mdh(i).JointPosition = Homejointpositions(i);
% end
getTransform(frankarobot_mdh,frankarobot_mdh.homeConfiguration,'Franka_link7','base');

Starting_tcp_tform = getTransform(frankarobot_mdh,frankarobot_mdh.homeConfiguration,'Gripper_TCP','base');

%showdetails(frankarobot_mdh); %showdetails function does not support code generation
Jacobi_MATRIX = jacobian_cartesian(frankarobot_mdh,[0,0,0,-1.570796326794897,0,1.570796326794897,0.785398163397448],8)

    % eeOffset = 0.12;
    % eeBody = robotics.RigidBody('end_effector');
    % eeBody.Mass = 0;
    % eeBody.Inertia = [0 0 0 0 0 0];
    % setFixedTransform(eeBody.Joint,trvec2tform([eeOffset 0 0]));
    % addBody(robot,eeBody,'link5');

   
    %interactiveGUI.Configuration = randomConfiguration(gen3);
    %addConfiguration(interactiveGUI)
%disp(interactiveGUI.StoredConfigurations)