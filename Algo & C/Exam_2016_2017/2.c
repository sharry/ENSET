// Exercice 2 | Manipulation des matrices carrées
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;         // Ordre
    double **vals; // Valeurs
} Matrix;

// 1. Création d'une matrice
Matrix createMatrix(int n /*Ordre de la matrice*/)
{
    Matrix matrix;
    matrix.n = n;
    matrix.vals = (double **)malloc(sizeof(double *) * n);
    for (int i = 0; i < n; i++)
        matrix.vals[i] = (double *)calloc(sizeof(double), n);
    return matrix;
}
// 2. Saisie d'une matrice
void fillMatrix(Matrix matrix)
{
    double **p, *q;
    for (p = matrix.vals; p < matrix.vals + matrix.n; p++)
    {
        for (q = *p; q < *p + matrix.n; q++)
        {
            printf("[%d][%d] = ", (int)(p - matrix.vals), (int)(q - *p));
            scanf("%lf", q);
        }
    }
}
// 3. Affichage d'une matrice
void printMatrix(Matrix matrix)
{
    double **p, *q;
    for (p = matrix.vals; p < matrix.vals + matrix.n; p++)
    {
        for (q = *p; q < *p + matrix.n; q++)
        {
            printf("%10.2f\t", *q);
        }
        printf("\n");
    }
}
// 4. La somme de deux matrice
Matrix addMatrices(Matrix matrix1, Matrix matrix2)
{
    Matrix sum;
    if (matrix1.n != matrix2.n)
    {
        sum.n = 0;
        return sum;
    }
    sum = createMatrix(matrix1.n);
    for (int i = 0; i < sum.n; i++)
    {
        for (int j = 0; j < sum.n; j++)
        {
            sum.vals[i][j] = matrix1.vals[i][j] + matrix2.vals[i][j];
        }
    }
    return sum;
}
// 5. Le produit de deux matrices
Matrix multiplyMatrices(Matrix matrix1, Matrix matrix2)
{
    Matrix product;
    if (matrix1.n != matrix2.n)
    {
        product.n = 0;
        return product;
    }
    product = createMatrix(matrix1.n);
    for (int i = 0; i < product.n; i++)
    {
        for (int j = 0; j < product.n; j++)
        {
            for (int k = 0; k < product.n; k++)
            {
                product.vals[i][j] += matrix1.vals[i][k] * matrix2.vals[k][j];
            }
        }
    }
    return product;
}
// 6. La trace d'une matrice
double matrixTrace(Matrix matrix)
{
    double trace = 0;
    for (int i = 0; i < matrix.n; i++)
    {
        trace += matrix.vals[i][i];
    }
    return trace;
}
// Tests
int main(int argc, char const *argv[])
{
    printf("\nDefinissez la taille de votre matrice A: ");
    int n1;
    scanf("%d", &n1);
    Matrix matA = createMatrix(n1);
    printf("Saisir les valeurs:\n");
    fillMatrix(matA);
    printf("\nDefinissez la taille de votre matrice B: ");
    int n2;
    scanf("%d", &n2);
    Matrix matB = createMatrix(n2);
    printf("Saisir les valeurs:\n");
    fillMatrix(matB);
    printf("\nVotre matrice A (%dx%d) est:\n", matA.n, matA.n);
    printMatrix(matA);
    printf("Sa trace est: tr(A) = %10.2f\n", matrixTrace(matA));
    printf("\nVotre matrice B (%dx%d) est:\n", matB.n, matB.n);
    printMatrix(matB);
    printf("Sa trace est: tr(B) = %10.2f\n", matrixTrace(matB));
    Matrix sum = addMatrices(matA, matB);
    Matrix product = multiplyMatrices(matA, matB);
    if (sum.n == 0)
    {
        printf("\nL'addition est impossible");
        printf("\nLa multiplication est impossible");
    }
    else
    {
        printf("\nLa somme de ces deux matrice est: \n");
        printMatrix(sum);
        printf("\nLe produit de ces deux matrice est: \n");
        printMatrix(product);
    }
    return 0;
}
