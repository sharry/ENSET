% Gauss-Jordan elimination
function [rref, solset] = GaussJordan(aug)
rref = REF(aug);
n = min(size(rref));
for i = n : -1 : 1
    for j = i - 1 : -1 : 1
        c = rref(j,i) / rref(i,i);
        rref(j,i) = rref(j,i) - (c * rref(i,i));
        rref(j, n+1) = rref(j, n+1) - (c * rref(i, n+1));
    end
end
for i = 1 : n
    rref(i, n+1) = rref(i, n+1) / rref(i,i);
    rref(i,i) = 1;
end
solset = rref(:, n+1);