function objVal = objFun(q_vel, jacobi, xd_eff_vel, starting_joint_vel, joint_values,jointVelocityWeightMatrix, config,slackIsUsed)
n_joints = length(joint_values);
% Add the cost for the slack variables
if slackIsUsed

    objVal = configurableObjective(q_vel(1:n_joints), jacobi, xd_eff_vel, starting_joint_vel, joint_values,jointVelocityWeightMatrix, config) + config.SlackObjectiveWeight * q_vel(n_joints+1:end)' * diag(config.SlackPenaltyWeight) * q_vel(n_joints+1:end);
else
    objVal = configurableObjective(q_vel(1:n_joints), jacobi, xd_eff_vel, starting_joint_vel, joint_values,jointVelocityWeightMatrix, config);
end
end