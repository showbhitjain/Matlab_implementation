%T_current: Current transformation  of endeffector to base
%desired_q should be 1x4
function [qe] = compute_orientation_Error(T_current,desired_q)

 current_quaternion = tmatrix2quat(T_current);
qe = computequatError(desired_q,current_quaternion,T_current);

end