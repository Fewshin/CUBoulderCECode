clear all

format long

xn = 2.12;
xn1 = 2.12;
comp1 = 0;
comp2 = 99999;

count = 0;

while comp1 ~= comp2
    xn = xn1;
    xn1 = xn - f(xn)/fp(xn);
    disp(xn1)
    count = count + 1;
    comp1 = round(xn * 10^8);
    comp2 = round(xn1 * 10^8);
end

function ret = f(x)
    ret = -x^6 + 4*x^4 + 5*x^2 - 5;
end

function ret = fp(x)
    ret = -6*x^5 + 16*x^3 + 10*x;
end