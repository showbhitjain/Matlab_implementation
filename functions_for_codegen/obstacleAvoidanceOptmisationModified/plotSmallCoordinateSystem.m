function plotSmallCoordinateSystem(T, scale)
    % This function takes a 4x4 transformation matrix T and a scale factor, and plots a smaller coordinate system.
    
    % Validate the input is a 4x4 matrix
    if size(T, 1) ~= 4 || size(T, 2) ~= 4
        error('Input must be a 4x4 matrix');
    end
    
    % Validate the scale
    if nargin < 2
        scale = 1; % Default scale if none provided
    end
    
    % Define the origin and scaled unit vectors for the standard basis
    origin = [0; 0; 0; 1];
    xAxis = [scale; 0; 0; 1];
    yAxis = [0; scale; 0; 1];
    zAxis = [0; 0; scale; 1];
    
    % Apply the transformation matrix to the origin and scaled basis vectors
    transOrigin = T * origin;
    transXAxis = T * xAxis;
    transYAxis = T * yAxis;
    transZAxis = T * zAxis;
    
    % Extract the 3D components for plotting
    transOrigin3D = transOrigin(1:3);
    transXAxis3D = transXAxis(1:3);
    transYAxis3D = transYAxis(1:3);
    transZAxis3D = transZAxis(1:3);
    
    % Plot the axes
  
    quiver3(transOrigin3D(1), transOrigin3D(2), transOrigin3D(3), ...
            transXAxis3D(1)-transOrigin3D(1), transXAxis3D(2)-transOrigin3D(2), transXAxis3D(3)-transOrigin3D(3), 'r', 'LineWidth', 2);
    quiver3(transOrigin3D(1), transOrigin3D(2), transOrigin3D(3), ...
            transYAxis3D(1)-transOrigin3D(1), transYAxis3D(2)-transOrigin3D(2), transYAxis3D(3)-transOrigin3D(3), 'g', 'LineWidth', 2);
    quiver3(transOrigin3D(1), transOrigin3D(2), transOrigin3D(3), ...
            transZAxis3D(1)-transOrigin3D(1), transZAxis3D(2)-transOrigin3D(2), transZAxis3D(3)-transOrigin3D(3), 'b', 'LineWidth', 2);
    
    % Set labels and title
    xlabel('X');
    ylabel('Y');
    zlabel('Z');
    %title('Transformed Coordinate System - Scaled');
    axis equal;
    rotate3d on;
end