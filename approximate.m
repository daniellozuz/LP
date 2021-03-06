row_offset = 1;
data = csvread('inductance.csv', row_offset);
inductance = data(:, 1);
distance = data(:, 2);
fit_type = fittype( @(a,b,c,x) a+b*exp(c*x), 'independent', 'x', 'coefficients', {'a', 'b', 'c'});
start_point = [0.1, 0.1, -250];

fit_function = fit(distance, inductance, fit_type, 'StartPoint', start_point);

hold on;
plot(distance, fit_function(distance));
plot(distance, inductance, 'r.');

% Pochodna robi sie tak:
differentiate(fit_function, [1, 2, 3]);
