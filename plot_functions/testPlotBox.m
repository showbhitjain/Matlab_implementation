%% Define Box Parameters
% Center of the box
center = [1, 2, 3];  % example center

% Box dimensions along its local x, y, and z axes
dims = [2, 3, 4];    % [length_x, length_y, length_z]

% Define the orientation as a quaternion [w, x, y, z]
% For example, a 45 degree rotation about the x-axis:
q = [cos(pi/8), 0, 0, sin(pi/8)];

%% Convert Quaternion to Rotation Matrix
% If you have the Robotics System Toolbox or Aerospace Toolbox, you can use:
R = quat2rotm(q);  % q must be in the form [w x y z]

%% Define Box Vertices in the Local (Box) Frame
% Create the 8 corners of the box. The box is centered at the origin.
lx = dims(1)/2; ly = dims(2)/2; lz = dims(3)/2;
localVertices = [ -lx, -ly, -lz;
                   lx, -ly, -lz;
                   lx,  ly, -lz;
                  -lx,  ly, -lz;
                  -lx, -ly,  lz;
                   lx, -ly,  lz;
                   lx,  ly,  lz;
                  -lx,  ly,  lz];

%% Transform Vertices to Global Frame
% Apply the rotation and then translation.
globalVertices = (R * localVertices')' + center;

%% Define the Faces of the Box
faces = [1 2 3 4;  % bottom face
         5 6 7 8;  % top face
         1 2 6 5;  % side face
         2 3 7 6;
         3 4 8 7;
         4 1 5 8];

%% Plot the Box
figure;
patch('Vertices', globalVertices, 'Faces', faces, ...
      'FaceColor', 'cyan', 'FaceAlpha', 0.5);
hold on;
grid on;
axis equal;
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Box with Orientation and Coordinate Frame');

%% Plot the Box Coordinate Frame at its Center
% Define the local axes (unit vectors along each axis) scaled for visualization
axisLength = max(dims)*0.8;  % scale factor for arrow length
x_axis_local = [axisLength, 0, 0]';
y_axis_local = [0, axisLength, 0]';
z_axis_local = [0, 0, axisLength]';

% Transform the local axes to the global frame using the rotation matrix.
x_axis_global = R * x_axis_local;
y_axis_global = R * y_axis_local;
z_axis_global = R * z_axis_local;

% Plot arrows using quiver3
quiver3(center(1), center(2), center(3), x_axis_global(1), x_axis_global(2), x_axis_global(3),...
    'Color','r','LineWidth',2, 'MaxHeadSize', 0.5);
quiver3(center(1), center(2), center(3), y_axis_global(1), y_axis_global(2), y_axis_global(3),...
    'Color','g','LineWidth',2, 'MaxHeadSize', 0.5);
quiver3(center(1), center(2), center(3), z_axis_global(1), z_axis_global(2), z_axis_global(3),...
    'Color','b','LineWidth',2, 'MaxHeadSize', 0.5);

% Add labels for the coordinate axes
text(center(1)+x_axis_global(1), center(2)+x_axis_global(2), center(3)+x_axis_global(3), 'X','FontSize',12,'Color','r');
text(center(1)+y_axis_global(1), center(2)+y_axis_global(2), center(3)+y_axis_global(3), 'Y','FontSize',12,'Color','g');
text(center(1)+z_axis_global(1), center(2)+z_axis_global(2), center(3)+z_axis_global(3), 'Z','FontSize',12,'Color','b');

hold off;