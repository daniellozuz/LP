function [Lprim] = evaluateLprim(x)

L = 0.1091;
s = 0.0077;

Lprim = (-L/s)*exp(-x/s);

end

