% Lagrange interpolation

function P = Lagrange(X, Y)
n = length(X);
L = zeros(n, n);
for i = 1 : n
    v = 1;
    for j = 1 : n
        if i ~= j
          v = conv(v, poly(X(j))) / (X(i) - X(j));
        end
    end
    L(i, :) = v * Y(i);
end
P = sum(L);