function [A, B] = get_AB(R,m,L,x1,x2,x3)

approximate;

cj = differentiate(fit_function, x1); % Czy to o to chodzi?

A = [0,  1,  0;
    x3^2*cj/(2*m),  0,  x3*cj/m;
    0,  -x3*cj/L,  -R/L-x2*cj/L];

B = [0, 0, 1/L]; % B nie powinno byc [0; 0; 1/L]?
