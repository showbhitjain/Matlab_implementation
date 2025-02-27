%% Cylinder Parameters
center = [0,0, 1];            % Cylinder center
% axisVec = [0.5774, 0.5774, 0.5774];  % Normalized axis (example)
axisVec = [0, 0, 1];  
radius = 0.5;                    % Cylinder radius
height = 2;                    % Cylinder height

% Number of points to define the circular cross-section
nPoints = 50;

%% Create Cylinder Along Z-axis and Scale Z
[Xc, Yc, Zc] = cylinder(radius, nPoints);
% Adjust Z so that the cylinder is centered about zero in z
Zc = (Zc - 0.5)*height;

%% Compute Rotation Matrix to Align Z-axis with axisVec
z_axis = [0, 0, 1];
v = cross(z_axis, axisVec);
s = norm(v);
if s < 1e-6
    R = eye(3);
else
    c = dot(z_axis, axisVec);
    vx = [   0   -v(3)   v(2);
           v(3)    0    -v(1);
          -v(2)  v(1)     0];
    R = eye(3) + vx + vx*vx*((1-c)/(s^2));
end

%% Transform Cylinder Coordinates
[nr, nc] = size(Xc);
Xg = zeros(nr, nc);
Yg = zeros(nr, nc);
Zg = zeros(nr, nc);
for i = 1:nr
    for j = 1:nc
        % Original point in the default frame
        pt = [Xc(i,j); Yc(i,j); Zc(i,j)];
        % Rotate the point
        pt_rot = R * pt;
        % Translate to the specified center
        pt_global = pt_rot + center';
        Xg(i,j) = pt_global(1);
        Yg(i,j) = pt_global(2);
        Zg(i,j) = pt_global(3);
    end
end

%% Plot the Lateral Surface of the Cylinder
figure;
surf(Xg, Yg, Zg, 'FaceAlpha', 0.7, 'EdgeColor', 'none','FaceColor','red');
hold on;
colormap parula;
axis equal;
xlabel('X'); ylabel('Y'); zlabel('Z');
title('Completely Closed Cylinder with Axis');

%% Create and Plot the Top and Bottom Caps
% Top cap: take the last row of points (corresponding to z = height/2)
topX = Xg(end, :);
topY = Yg(end, :);
topZ = Zg(end, :);
% Bottom cap: take the first row of points (corresponding to z = -height/2)
botX = Xg(1, :);
botY = Yg(1, :);
botZ = Zg(1, :);

% Create patches for the caps. The points must be ordered correctly.
patch(topX, topY, topZ, 'red', 'FaceAlpha', 0.7);
patch(botX, botY, botZ, 'red', 'FaceAlpha', 0.7);

%% Plot the Cylinder's Central Axis
halfH = height/2;
startPoint = center - halfH * axisVec;
endPoint   = center + halfH * axisVec;
quiver3(center(1), center(2), center(3), axisVec(1)*height, axisVec(2)*height, axisVec(3)*height, ...
    'Color','k','LineWidth',2,'MaxHeadSize',0.5);
text(endPoint(1), endPoint(2), endPoint(3), 'Axis','FontSize',12,'Color','k');

hold off;