% Variables
% X1  - distance to electromagnet [m]
% X2  - velocity                  [m/s]
% X3  - coil current              [A]
% V   - steering voltage          [V]

g = 9.81;
m = 0.057;
i_s = 1.506;     % fix it?
k = 0.29703;
tau = 10.7;
s = 0.0077;

% V_min = 5.56;
% V_max = 9.56;
% 
% X1_r = 0.014;   % fix it?
% X2_r = 0;
% X3_r = 0.7139;
% V_r = 7.4734;
% 
% X1_dot = X2_;
% X2_dot = ( evaluateLprim(X1) / (2*m) ) * (X3)^2 + g;
% X3_dot = (1/tau) * (k*V - i_s - X3);


alfa = s;
beta = sqrt(g*s);
gamma = 0.2889;
epsilon = 0.0281;
eta = 10.2870;

X1 = alfa * x1;
X2 = beta * x2;
X3 = gamma * x3;
V = (eta * u * tau + i_s) / k;
T = epsilon * t;

x1_dot = x2;
x2_dot = -exp(-x1) * x3^2 + 1;
c = 2.6263;     % (1/tau) * sqrt(s/g)
x3_dot = -c*x3 + u;

x1_r = 1.8094;
x2_r = 0;
x3_r = 2.4712;
u_r = 6.4899;

u_min = 1.32;
u_max = 12.12;










