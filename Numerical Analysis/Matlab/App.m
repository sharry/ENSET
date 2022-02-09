augmented = [1,1,0,3,4 ; 2,1,-1,1,1 ; 3,-1,-1,2,-3 ; -1,2,3,-1,4];
rowechelon = REF(augmented);
solset = round(Gauss(augmented));
[L, U] = LU(augmented);
[rref, sols] = GaussJordan(augmented);

matr = [1,1,3; 1,5,5; 3,5,19];
M = Cholesky(matr);

X = [1, 2, 4];
Y = [2, 5, 2];
polynomial = Lagrange(X, Y);

A = [4, -1, 0; -1, 4, -1; 0, -1, 4];
b = [6 4 6];
init = [0 0 0];

x = Jacobi(A, b, init, 10);
y = GaussSeidel(A, b, init, 100);