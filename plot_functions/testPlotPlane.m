%% Plane Parameters
planeCenter = [4, -1, 2];           % Center of the plane
planeNormal = [0.2, 0.5, 0.84];       % Given normal (not necessarily unit length)
planeNormal = planeNormal / norm(planeNormal);  % Normalize the normal

% Define the extents (half-lengths) along two in-plane directions
halfWidth = 3;    % extent along first in-plane direction
halfLength = 2;   % extent along second in-plane direction

% Define the thickness (width) along the negative normal direction
thickness = 0.2;  % small width in -ve normal direction

%% Compute two orthonormal vectors in the plane
% Pick a temporary vector not parallel to planeNormal
if abs(dot(planeNormal, [0,0,1])) < 0.99
    tempVec = [0,0,1];
else
    tempVec = [0,1,0];
end
inPlane1 = cross(planeNormal, tempVec);
inPlane1 = inPlane1 / norm(inPlane1);
inPlane2 = cross(planeNormal, inPlane1);
inPlane2 = inPlane2 / norm(inPlane2);

%% Define the "top" face of the plane (the patch in the plane)
corner1 = planeCenter + halfWidth*inPlane1 + halfLength*inPlane2;
corner2 = planeCenter - halfWidth*inPlane1 + halfLength*inPlane2;
corner3 = planeCenter - halfWidth*inPlane1 - halfLength*inPlane2;
corner4 = planeCenter + halfWidth*inPlane1 - halfLength*inPlane2;
topFace = [corner1; corner2; corner3; corner4];

%% Define the "bottom" face by offsetting the top face along -planeNormal
bottomFace = topFace - thickness * planeNormal;

%% Plot the Plane with Thickness
figure;
hold on;
% Plot top face
patch('Vertices', topFace, 'Faces', [1 2 3 4], 'FaceColor', [0.8 0.8 1], 'FaceAlpha', 0.7);
% Plot bottom face
patch('Vertices', bottomFace, 'Faces', [1 2 3 4], 'FaceColor', [0.8 0.8 1], 'FaceAlpha', 0.7);
% Connect corresponding edges to give the appearance of thickness
for i = 1:4
    plot3([topFace(i,1) bottomFace(i,1)], [topFace(i,2) bottomFace(i,2)], [topFace(i,3) bottomFace(i,3)], 'k-', 'LineWidth', 1);
end

axis equal;
xlabel('X'); ylabel('Y'); zlabel('Z');
title('Plane with Thickness (Width in -ve Normal Direction)');

%% Plot the Normal Axis from the Plane Center
normalLength = max(halfWidth, halfLength);
quiver3(planeCenter(1), planeCenter(2), planeCenter(3), ...
    planeNormal(1)*normalLength, planeNormal(2)*normalLength, planeNormal(3)*normalLength, ...
    'Color','r','LineWidth',2, 'MaxHeadSize',0.5);
text(planeCenter(1)+planeNormal(1)*normalLength, ...
     planeCenter(2)+planeNormal(2)*normalLength, ...
     planeCenter(3)+planeNormal(3)*normalLength, 'Normal','FontSize',12,'Color','r');

%% Optionally, Plot the In-Plane Axes
quiver3(planeCenter(1), planeCenter(2), planeCenter(3), ...
    inPlane1(1)*halfWidth, inPlane1(2)*halfWidth, inPlane1(3)*halfWidth, ...
    'Color','g','LineWidth',2, 'MaxHeadSize',0.5);
quiver3(planeCenter(1), planeCenter(2), planeCenter(3), ...
    inPlane2(1)*halfLength, inPlane2(2)*halfLength, inPlane2(3)*halfLength, ...
    'Color','b','LineWidth',2, 'MaxHeadSize',0.5);
text(planeCenter(1)+inPlane1(1)*halfWidth, planeCenter(2)+inPlane1(2)*halfWidth, planeCenter(3)+inPlane1(3)*halfWidth, 'Dir1','FontSize',12,'Color','g');
text(planeCenter(1)+inPlane2(1)*halfLength, planeCenter(2)+inPlane2(2)*halfLength, planeCenter(3)+inPlane2(3)*halfLength, 'Dir2','FontSize',12,'Color','b');

hold off;
