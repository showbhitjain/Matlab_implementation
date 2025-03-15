close all;
actualPositionTCP = readmatrix('Experiment1/actualPositionTCP.csv');
desiredPositionTCP = readmatrix('Experiment1/desiredTcpTrajectory.csv');
distanceAllLinks =  readmatrix('Experiment1/distanceAllLinks.csv');
errorPositionTCP = readmatrix('Experiment1/errorPositionTCP.csv');
minimumDistanceRobotObstacles = readmatrix('Experiment1/minimumDistanceRobotObstacles.csv');
d_influence = 0.1;
d_stop = 0.03;
k = 50;

k_min = (d_stop + d_influence)/d_influence;
k_max =  (d_stop + d_influence)/d_stop;
d_0 = (d_influence + d_stop)/k;

d_0_min = (d_influence + d_stop)/k_max;
d_0_max = (d_influence + d_stop)/k_min;
time = 0:0.001:20.001;

figure();
plot(time,errorPositionTCP(1,1:end));
hold on;
grid on;

plot(time,errorPositionTCP(2,1:end));
plot(time,errorPositionTCP(3,1:end));
legend('e_x','e_y','e_z');
title('Translational error TCP')
xlabel('Time (s)');
ylabel('Position Error (m)');
xlim([0 20]);
hold off;

figure();
plot(time,minimumDistanceRobotObstacles);

hold on;
grid on;
yline(d_influence, 'r--');  % Red dashed line for d_2 
yline(d_stop, 'g--');  % Green dashed line for d_1 

yline(d_0, 'b--'); % Blue dashed line for d_0 
legend('d_{min}','d_2','d_1','d_0');
xlabel('Time (s)');
ylabel('Distance (m)');
title('d_{min} between Robot and obstacles');
xlim([0 20]);
hold off;

figure();
plot3(desiredPositionTCP(1,:), desiredPositionTCP(2,:), desiredPositionTCP(3,:), '.-', 'Color', [0.58, 0, 0.83]);

hold on;
plot3(actualPositionTCP(1,:), actualPositionTCP(2,:), actualPositionTCP(3,:), '.-', 'Color', [0.58, 0, 0.83]);
legend('desiredTCP','actualTCP')
 xlabel('X-axis'); ylabel('Y-axis'); zlabel('Z-axis');
 xlim([-0.2,0.7]);
 ylim([-0.9,0.9])
 zlim([-0.1,0.9])


 % Assuming distanceAllLinks is already loaded or defined
[numLinks, numSamples] = size(distanceAllLinks);

% Validate that time matches number of columns in distanceAllLinks
if length(time) ~= numSamples
    error('Time vector and distanceAllLinks columns must match!');
end




% Create figure
figure;
hold on;
colors = lines(numLinks); % Generate distinct colors
legendLabels = cell(numLinks,1); % Preallocate legend labels

% Loop through each row of distanceAllLinks and plot it
for i = 1:numLinks
    if i < numLinks
        % Label as "Link i->i+1" with an arrow notation
        legendLabels{i} = sprintf('Link %d \\rightarrow %d', i-1, i);
    else
        % Last row: Label as "final link"
        legendLabels{i} = 'Final Link';
    end
    plot(time, distanceAllLinks(i,:), 'Color', colors(i,:), 'LineWidth', 1.5);
end

% Customize the plot
xlabel('Time (seconds)');
ylabel('Distance');
title('Distance of Links Over Time');
legend(legendLabels, 'Location', 'best');
grid on;
hold off;

