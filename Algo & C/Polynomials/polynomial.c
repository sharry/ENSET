#include "polynomial.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Create a new polynomial
Polynomial *newPolynomial(int degree, double *coeff)
{
    Polynomial *P;
    P->degree = degree;
    P->coeff = (double *)calloc(degree, sizeof(double));
    for (int i = 0; i < degree; i++)
        P->coeff[i] = coeff[i];

    return P;
}

// Print to the console a given polynomial
void printPolynomial(Polynomial *P)
{
    printf("P(x) = ");
    bool started = false;
    for (int i = 0; i < P->degree; i++)
    {
        if (P->coeff[i] != 0)
        {
            if (P->coeff[i] > 0 && started)
                printf("+ ");
            else if (P->coeff[i] < 0)
            {
                printf("-");
                printf(i == 0 ? "" : " ");
            }
            double currCoeff = abs(P->coeff[i]);
            switch (i)
            {
            case 0:
                printf("%.2lf ", currCoeff);
                started = true;
                break;
            case 1:
                if (currCoeff == 1)
                    printf("x ");
                else
                    printf("%.2lf x ", currCoeff);
                started = true;
                break;
            default:
                if (currCoeff == 1)
                    printf("x^%d ", i);
                else
                    printf("%.2lf x^%d ", currCoeff, i);
                started = true;
                break;
            }
        }
    }
}

// Calculate P(x)
double P(Polynomial *P, double x)
{
    double Px;
    for (int i = 0; i < P->degree; i++)
        Px += P->coeff[i] * pow(x, i);
    return Px;
}

// Polynomials addition
Polynomial *add(Polynomial *P, Polynomial *Q)
{
    
}

int main(int argc, char const *argv[])
{
    double coeff[4];
    coeff[0] = -4;
    coeff[1] = -3;
    coeff[2] = 4;
    coeff[3] = -1;
    printf("Polynomial operations\n");
    Polynomial *p = newPolynomial(4, coeff);
    printPolynomial(p);
    printf("\nP(4) = %.2lf", P(p, 4));
    return 0;
}
