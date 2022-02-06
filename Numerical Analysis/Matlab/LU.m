% LU decomposition
function [Lower, Upper] = LU(mat)
if (max(size(mat)) ~= min(size(mat)))
    mat(:, max(size(mat))) = [];
end
Lower = mat;
n = min(size(mat));
for i = 1 : n
    for j = i+1 : n
        c = mat(j, i) / mat(i,i);
        Lower(j,i) = c;
        for k = i : n
            mat(j,k) = mat(j,k) -  (c * mat(i,k));
        end
    end
end
for i = 1 : n
    for j = 1 : n
        if (i == j)
            Lower(i,j) = 1;
        elseif (i < j)
            Lower(i, j) = 0;
        end
    end
end
Upper = mat;