augmented = [1,1,0,3,4 ; 2,1,-1,1,1 ; 3,-1,-1,2,-3 ; -1,2,3,-1,4];
rowechelon = REF(augmented);
solset = round(Gauss(augmented));
[L, U] = LU(augmented);