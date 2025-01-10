function [desired_joint_vector] = integrateRungeKutta(desired_joint_velocity_current,tspan,start_joint_Velocity)
%INTEGRATERUNGEKUTTA Summary of this function goes here
%   Detailed explanation goes here
[~,Y] = ode45(@(t,X)joint_dynamics_integrate(t,X,desired_joint_velocity_current),tspan,start_joint_Velocity);
% The new joint positions are the last row of Y
desired_joint_vector = Y(end, :)';
end


     
    