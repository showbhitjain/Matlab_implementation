function objVal = objFun(q_vel, jacobi, xd_eff_vel, starting_joint_vel, joint_values, config)
    n_joints = length(joint_values);
    objVal = configurableObjective(q_vel(1:n_joints), jacobi, xd_eff_vel, starting_joint_vel, joint_values, config);
    
end