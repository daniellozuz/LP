clear all;
close all;

% Data to approx line
a = 0.1017;
b = 0.01801;
c = -158.7;

% Data general
g = 9.81;
m = 0.057;
R = 4;

% Function handler to L, dL/dx, d2L/(dx)2
base = @(x1)(a+b*exp(c*x1));
first = @(x1)(c*b*exp(c*x1));
second = @(x1)(c*c*b*exp(c*x1));

% Calculating x_0
x1_0 = 0.005;
x2_0 = 0;
x3_0 = sqrt((-2*m*g)/first(x1_0));
u_0 = R*x3_0;

x_0 = [x1_0 x2_0 x3_0];

% Calculating A matrix
A11 = 0;
A12 = 1;
A13 = 0;

A21 = second(x1_0)*(x3_0)*(x3_0)/(2*m);
A22 = 0;
A23 = first(x1_0)*x3_0/m;

A31 = 0;
A32 = first(x1_0)*x3_0/(base(x1_0));
A33 = - R/base(x1_0);

A = [A11, A12, A13
    A21, A22, A23
    A31, A32, A33];

% Calculating B matrix

B31 = 1/base(x1_0);

B = [0
    0
    B31];

% Designing LQR
Q = eye(size(A));
R = 1;

[K,~,~] = lqr(A,B,Q,R,0);