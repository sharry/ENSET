function x = Jacobi(A, b, init, itr)
n = min(size(A));
x = init;
for k = 1 : itr
    for i = 1 : n
        sum = 0;
        for j = 1 : n
            if j ~= i
                sum = sum + A(i,j) * x(j);
            end
        end
        x(i) = (1 / A(i,i)) * (b(i) - sum);
    end
end