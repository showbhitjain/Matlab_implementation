function [jacobi] = rearrangejacobi(J)
%use only if using the toolbox jacobi is used as input


J_i = zeros(6,7);
J_i(1:3,1:end) = J(4:end,1:end);
J_i(4:end,1:end) = J(1:3,1:end);
jacobi = J_i;


end
