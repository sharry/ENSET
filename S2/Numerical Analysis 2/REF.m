% Row echelon form
function ref = REF(aug)
    for i = 1 : min(size(aug))
        pivot = abs(aug(i,i));
        pivotRow = i;
        for j = i+1 : min(size(aug))
            if abs(aug(j,i)) > pivot
                pivot = aug(j,i);
                pivotRow = j;
            end
        end
        for j = i : max(size(aug))
            tmp = aug(pivotRow, j);
            aug(pivotRow, j) = aug(i,j);
            aug(i,j) = tmp;
        end

        for j = i+1 : min(size(aug))
            c = aug(j,i) / aug(i,i);
            for k = i : max(size(aug))
                aug(j,k) = aug(j,k) - (c * aug(i,k));
            end
        end
    
    end
    ref = max(size(aug));
    for i = 1 : min(size(aug))
        for j = 1 : max(size(aug))
            ref(i,j) = aug(i,j);
        end
    end
end