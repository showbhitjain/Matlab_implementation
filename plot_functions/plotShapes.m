%% Clear and set up figure
clear; clc;
figure;
hold on;
axis equal;
grid on;
xlabel('X'); ylabel('Y'); zlabel('Z');
title('Combined Plot: Cylinder, Box, and Plane');
view(3);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 1. Plot a Closed Cylinder
% Cylinder parameters
cyl_center = [4, 2, 3];                  % Center of the cylinder
cyl_axis   = [0.5774, 0.5774, 0.5774];    % Normalized axis
cyl_radius = 1;                          % Cylinder radius
cyl_height = 5;                          % Cylinder height

% Create cylinder along the z-axis using nPoints around the circle
nPoints = 50;
[Xc, Yc, Zc] = cylinder(cyl_radius, nPoints);
% Scale Z to span the given height, centered at zero
Zc = (Zc - 0.5)*cyl_height;

% Compute rotation matrix to align [0 0 1] with cyl_axis
z_axis = [0, 0, 1];
v = cross(z_axis, cyl_axis);
s = norm(v);
if s < 1e-6
    R_cyl = eye(3);
else
    c = dot(z_axis, cyl_axis);
    vx = [    0   -v(3)   v(2);
           v(3)      0   -v(1);
          -v(2)   v(1)      0];
    R_cyl = eye(3) + vx + vx*vx*((1-c)/(s^2));
end

% Transform cylinder coordinates: rotate and then translate
[nr, nc] = size(Xc);
Xg = zeros(nr, nc); Yg = zeros(nr, nc); Zg = zeros(nr, nc);
for i = 1:nr
    for j = 1:nc
        pt = [Xc(i,j); Yc(i,j); Zc(i,j)];
        pt_rot = R_cyl * pt;
        pt_global = pt_rot + cyl_center';
        Xg(i,j) = pt_global(1);
        Yg(i,j) = pt_global(2);
        Zg(i,j) = pt_global(3);
    end
end

% Plot the lateral surface of the cylinder
surf(Xg, Yg, Zg, 'FaceAlpha', 0.7, 'EdgeColor', 'none', 'FaceColor', 'cyan');

% Plot the top and bottom end-caps using patches
topX = Xg(end, :); topY = Yg(end, :); topZ = Zg(end, :);
botX = Xg(1, :);  botY = Yg(1, :);  botZ = Zg(1, :);
patch(topX, topY, topZ, 'cyan', 'FaceAlpha', 0.7);
patch(botX, botY, botZ, 'cyan', 'FaceAlpha', 0.7);

% Plot the cylinder's central axis
halfH = cyl_height/2;
quiver3(cyl_center(1), cyl_center(2), cyl_center(3), ...
    cyl_axis(1)*cyl_height, cyl_axis(2)*cyl_height, cyl_axis(3)*cyl_height, ...
    'Color','k','LineWidth',2, 'MaxHeadSize',0.5);
text(cyl_center(1)+cyl_axis(1)*halfH, cyl_center(2)+cyl_axis(2)*halfH, cyl_center(3)+cyl_axis(3)*halfH, ' Axis','FontSize',12,'Color','k');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 2. Plot an Oriented Box
% Box parameters
box_center = [-4, 0, 2];    % Center of the box
box_dims   = [2, 3, 4];     % Complete dimensions along box's local x,y,z

% Define the box orientation as a quaternion [w x y z]
% For example, a 45° rotation about the x-axis:
q = [cos(-pi/8), 0, 0, sin(-pi/8)];
% Convert quaternion to rotation matrix (requires Aerospace or Robotics Toolbox)
R_box = quat2rotm(q);  % [w x y z] format

% Define 8 vertices of the box in its local frame (centered at origin)
lx = box_dims(1)/2; ly = box_dims(2)/2; lz = box_dims(3)/2;
localVertices = [ -lx, -ly, -lz;
                   lx, -ly, -lz;
                   lx,  ly, -lz;
                  -lx,  ly, -lz;
                  -lx, -ly,  lz;
                   lx, -ly,  lz;
                   lx,  ly,  lz;
                  -lx,  ly,  lz];

% Transform vertices to global coordinates
globalVertices_box = (R_box * localVertices')' + box_center;

% Define the 6 faces of the box (indices into vertices)
faces_box = [1 2 3 4;    % bottom face
             5 6 7 8;    % top face
             1 2 6 5;    % side face
             2 3 7 6;
             3 4 8 7;
             4 1 5 8];

% Plot the box using patch
patch('Vertices', globalVertices_box, 'Faces', faces_box, 'FaceColor', 'yellow', 'FaceAlpha', 0.7);

% Plot the box coordinate frame (box local axes)
axisLength = max(box_dims)*0.8;
x_axis_local = [axisLength, 0, 0]';
y_axis_local = [0, axisLength, 0]';
z_axis_local = [0, 0, axisLength]';
x_axis_global = R_box * x_axis_local;
y_axis_global = R_box * y_axis_local;
z_axis_global = R_box * z_axis_local;
quiver3(box_center(1), box_center(2), box_center(3), x_axis_global(1), x_axis_global(2), x_axis_global(3), 'Color','r','LineWidth',2, 'MaxHeadSize',0.5);
quiver3(box_center(1), box_center(2), box_center(3), y_axis_global(1), y_axis_global(2), y_axis_global(3), 'Color','g','LineWidth',2, 'MaxHeadSize',0.5);
quiver3(box_center(1), box_center(2), box_center(3), z_axis_global(1), z_axis_global(2), z_axis_global(3), 'Color','b','LineWidth',2, 'MaxHeadSize',0.5);
text(box_center(1)+x_axis_global(1), box_center(2)+x_axis_global(2), box_center(3)+x_axis_global(3), 'X','FontSize',12,'Color','r');
text(box_center(1)+y_axis_global(1), box_center(2)+y_axis_global(2), box_center(3)+y_axis_global(3), 'Y','FontSize',12,'Color','g');
text(box_center(1)+z_axis_global(1), box_center(2)+z_axis_global(2), box_center(3)+z_axis_global(3), 'Z','FontSize',12,'Color','b');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 3. Plot a Plane with a Small Width in the -Normal Direction
% Plane parameters
plane_center  = [10, 0, 1];    % Center of the plane
plane_normal  = [0.2, 0.5, 0.84];  % Given normal (will be normalized)
plane_normal  = plane_normal / norm(plane_normal);
halfWidth     = 3;   % extent along first in-plane direction
halfLength    = 2;   % extent along second in-plane direction
thickness     = 0.2; % small width along -plane_normal

% Compute two orthonormal vectors lying in the plane
if abs(dot(plane_normal, [0,0,1])) < 0.99
    tempVec = [0,0,1];
else
    tempVec = [0,1,0];
end
inPlane1 = cross(plane_normal, tempVec);
inPlane1 = inPlane1 / norm(inPlane1);
inPlane2 = cross(plane_normal, inPlane1);
inPlane2 = inPlane2 / norm(inPlane2);

% Define the top face of the plane (a rectangle)
corner1 = plane_center + halfWidth*inPlane1 + halfLength*inPlane2;
corner2 = plane_center - halfWidth*inPlane1 + halfLength*inPlane2;
corner3 = plane_center - halfWidth*inPlane1 - halfLength*inPlane2;
corner4 = plane_center + halfWidth*inPlane1 - halfLength*inPlane2;
topFace = [corner1; corner2; corner3; corner4];

% Define the bottom face by offsetting along -plane_normal
bottomFace = topFace - thickness * plane_normal;

% Plot the top and bottom faces of the plane
patch('Vertices', topFace, 'Faces', [1 2 3 4], 'FaceColor', [0.9290 0.6940 0.1250], 'FaceAlpha', 0.7);
patch('Vertices', bottomFace, 'Faces', [1 2 3 4], 'FaceColor', [0.9290 0.6940 0.1250], 'FaceAlpha', 0.7);

% Connect corresponding corners to show thickness
for i = 1:4
    plot3([topFace(i,1) bottomFace(i,1)], [topFace(i,2) bottomFace(i,2)], [topFace(i,3) bottomFace(i,3)], 'k-', 'LineWidth', 1);
end

% Plot the plane's normal axis
normalLength = max(halfWidth, halfLength);
quiver3(plane_center(1), plane_center(2), plane_center(3), ...
    plane_normal(1)*normalLength, plane_normal(2)*normalLength, plane_normal(3)*normalLength, ...
    'Color','r','LineWidth',2, 'MaxHeadSize',0.5);
text(plane_center(1)+plane_normal(1)*normalLength, plane_center(2)+plane_normal(2)*normalLength, plane_center(3)+plane_normal(3)*normalLength, 'Normal','FontSize',12,'Color','r');

% Optionally, plot the in-plane axes
quiver3(plane_center(1), plane_center(2), plane_center(3), inPlane1(1)*halfWidth, inPlane1(2)*halfWidth, inPlane1(3)*halfWidth, 'Color','g','LineWidth',2, 'MaxHeadSize',0.5);
quiver3(plane_center(1), plane_center(2), plane_center(3), inPlane2(1)*halfLength, inPlane2(2)*halfLength, inPlane2(3)*halfLength, 'Color','b','LineWidth',2, 'MaxHeadSize',0.5);
text(plane_center(1)+inPlane1(1)*halfWidth, plane_center(2)+inPlane1(2)*halfWidth, plane_center(3)+inPlane1(3)*halfWidth, '1','FontSize',12,'Color','g');
text(plane_center(1)+inPlane2(1)*halfLength, plane_center(2)+inPlane2(2)*halfLength, plane_center(3)+inPlane2(3)*halfLength, '2','FontSize',12,'Color','b');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Finalize Plot

plotSphere([18,0,1],1)
axis equal
view(3);
camproj('orthographic');
hold off;
