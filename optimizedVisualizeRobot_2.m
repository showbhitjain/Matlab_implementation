function optimizedVisualizeRobot_2(rbtName, jointAnglesMatrix, waypoints, mode)
    persistent robot ax trajPlot wayptPlot  elapsedText
  
     
    
    if isempty(robot)
        % figure;
        robot = evalin('base', rbtName);
        robot.DataFormat = 'row';
        % ax = show(robot, robot.homeConfiguration, 'Frames', 'off');
        % hold on;
        % title('Robot Trajectory Visualization');
        % xlim([-1 1]), ylim([-1 1]), zlim([0 1.2]);
        % startTime = tic; % Start the timer
        % 
        % % Initialize elapsed time text display
        % elapsedText = text(0.05, 0.95, 'Elapsed Time: 0s', 'Units', 'normalized', ...
        %                     'VerticalAlignment', 'top', 'FontSize', 8, 'Parent', ax);
    end
    
    
    if isempty(ax) || ~isgraphics(ax)
        clf; %Clear the current figure window to start fresh 
        close;
        figure;
        ax = show(robot, robot.homeConfiguration, 'Frames', 'off');
        %ax = axes; %Create a new axes object
          hold on;
         title('Robot Trajectory Visualization');
         xlim([-1 1]), ylim([-1 1]), zlim([0 1.2]);
        %view(3); % Set the view to 3D
        
        
        %xlim(ax, [-1 1]), ylim(ax, [-1 1]), zlim(ax, [0 1.2]);
        %title(ax, 'Robot Trajectory Visualization');
        %hold(ax, 'on');

        % robot = evalin('base', rbtName);
        % robot.DataFormat = 'row';
        
        % Reinitialize all graphics objects
        wayptPlot = [];
        trajPlot = [];
        %elapsedText = text(ax, 0.05, 0.95, 'Elapsed Time: 0s', 'Units', 'normalized', ...
                           % 'VerticalAlignment', 'top', 'FontSize', 8);
    elapsedText = text(0.05, 0.95, 'Elapsed Time: 0s', 'Units', 'normalized', ...
                             'VerticalAlignment', 'top', 'FontSize', 12, 'Parent', ax);
     end
   
    
    
    

    if isempty(wayptPlot) && ~isempty(waypoints)
        wayptPlot = scatter3(ax,waypoints(1,:), waypoints(2,:), waypoints(3,:), 'ro', 'LineWidth', 2);
    end
    % Plot trajectory only if mode is 2 and it's the first function call or waypoints have changed
    if mode == 2 && (isempty(trajPlot) || ~isequal(waypoints, wayptPlot.XData))
        trajPlot = plot3(ax, waypoints(1,:), waypoints(2,:), waypoints(3,:), 'b.-');
    end
    % Determine the skipping rate based on desired duration and actual visualization capability
    % skipRate = 100; % Example: Adjust based on performance and desired duration
    % updateRate = 0.001 * skipRate; % Update the figure every 'skipRate' milliseconds
    realTimeStart = tic; % Restart the timer


     %totalElapsedTime = 0;
         idx = 1;
    while idx <= size(jointAnglesMatrix, 1)
        realTimeElapsed = toc(realTimeStart) * 1000; % Convert to milliseconds
        expectedTime = idx; % Expected time in ms, directly from idx

        if realTimeElapsed > expectedTime
            % Calculate how much to increase idx based on the time difference
            idxIncrease = floor((realTimeElapsed - expectedTime) / 1000 * 1000); % Example for skipRate of 100 ms
            idx = idx + idxIncrease;
        elseif realTimeElapsed < expectedTime
            % Pause for the difference to slow down the visualization
            pause((expectedTime - realTimeElapsed) / 1000); % Convert ms back to seconds
        end

        if idx > size(jointAnglesMatrix, 1)
            break; % Ensure idx does not exceed matrix size
        end

        jointAngles = jointAnglesMatrix(idx, :);
        show(robot, jointAngles, 'PreservePlot', false, 'Frames', 'off', 'Parent', ax);

        elapsedTime = toc(realTimeStart); % Update elapsed time in seconds
        set(elapsedText, 'String', sprintf('Elapsed Time: %.2fs', elapsedTime));
        drawnow limitrate;
        
        idx = idx + 1; % Move to the next frame
    end

    % for idx = 1:size(jointAnglesMatrix, 1)
    %     currentRealTime = toc(realTimeStart); % Current real-world time in seconds
    %     expectedTime = idx / 1000; % Expected time in seconds (1ms per index)
    % 
    %     if expectedTime > currentRealTime + totalElapsedTime
    %         % If the expected time exceeds the real-world time, skip frames
    %         skipRate = ceil((expectedTime - currentRealTime) * 1000); % Adjust skipRate dynamically
    %         idx = idx + skipRate; % Increase index to skip frames
    %         if idx > size(jointAnglesMatrix, 1)
    %             break; % Ensure the index does not exceed matrix bounds
    %         end
    %     elseif expectedTime < currentRealTime
    %         % If we are behind schedule, pause briefly to allow real-time to catch up
    %         pause(expectedTime - currentRealTime);
    %         totalElapsedTime = totalElapsedTime + (expectedTime - currentRealTime);
    %     end
    % 
    %     if idx <= size(jointAnglesMatrix, 1)
    %         jointAngles = jointAnglesMatrix(idx, :);
    %         % Efficiently update robot pose
    %         show(robot, jointAngles, 'PreservePlot', false, 'Frames', 'off', 'Parent', ax);
    %         % Update and display the elapsed time
    %         elapsedTime = toc(realTimeStart) + totalElapsedTime; % Adjust elapsed time
    %         set(elapsedText, 'String', sprintf('Elapsed Time: %.2fs', elapsedTime));
    %         drawnow limitrate;
    %     end
    % end
    % for idx = 1:skipRate:size(jointAnglesMatrix, 1)
    %     jointAngles = jointAnglesMatrix(idx, :);
    % 
    %     % Efficiently update robot pose
    %     show(robot, jointAngles, 'PreservePlot', false, 'Frames', 'off', 'Parent', ax);
    % 
    %     % Update and display the elapsed time
    %     elapsedTime = toc(startTime); % Measure elapsed time
    %     set(elapsedText, 'String', sprintf('Elapsed Time: %.2fs', elapsedTime));
    % 
    %     drawnow limitrate;
    % 
    %     % Pause to simulate real-time motion, adjust as needed based on actual performance
    %     %pause(updateRate);
    % end
end

