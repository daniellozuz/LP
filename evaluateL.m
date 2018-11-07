function [L] = evaluateL(x, u)

W = 2 * diag( [1 0 ; 0 1] );
R = 1;

L = (x - x_r)' * W * (x - x_r) + (u - u_r)' * R * (u - u_r);

end

