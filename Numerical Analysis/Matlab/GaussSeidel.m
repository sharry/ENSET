function x = GaussSeidel(A, b, init, itr)
n = min(size(A));
x = init;
for k = 1 : itr
    for i = 1 : n
        sum1 = 0;
        sum2 = 0;
        for j = 1 : i - 1
           sum1 = sum1 + A(i,j) * x(j);
        end
        for j = i+1 : n
            sum2 = sum2 + A(i,j) * x(j);
        end
        x(i) = (1 / A(i,i)) * (b(i) - sum1 - sum2);
    end
end

