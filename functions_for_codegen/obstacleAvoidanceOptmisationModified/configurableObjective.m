function objVal = configurableObjective(current_joint_velocity, jacobi, xd_eff_vel, starting_joint_vel, joint_values,WeightMatrix,config)
    objVal = 0;
    
    if config.useObjectiveNormInfinity
        objVal = objVal + config.weightNormInfinity * (norm(current_joint_velocity, Inf)^2) / 2;
    end
    
    if config.useObjectiveNormL2
        objVal = objVal + config.weightNormL2 * (current_joint_velocity' * WeightMatrix * current_joint_velocity) / 2;
    end
    
    if config.useObjectiveTrajectoryFollowing
        objVal = objVal + config.weightTrajectoryFollowing * norm((jacobi * current_joint_velocity - xd_eff_vel), 2)^2 / 2;
    end
    
    if config.useObjectiveJointAcceleration
        objVal =  objVal + config.weightJointAcceleration * ((current_joint_velocity - starting_joint_vel)' * WeightMatrix * (current_joint_velocity - starting_joint_vel)) /2 ;
    end

    if config.useObjectiveManipulability
      objVal  = objVal + config.weightManipulability * (-computeManipulabilityJacobian(joint_values') * current_joint_velocity);
    end  
    % You can add more terms similarly with their checks and weights
end
