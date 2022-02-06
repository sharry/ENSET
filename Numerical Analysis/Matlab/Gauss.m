% Gaussian elimination
function solset = Gauss(aug)
 ref = REF(aug);
 for i = min(size(ref)) : -1 : 1
    solset(i) = ref(i, max(size(ref))) / ref(i,i);
    for j = i - 1 : -1 : 1
        ref(j, max(size(ref))) = ref(j, max(size(ref))) - (ref(j,i) * solset(i));
    end
 end
 