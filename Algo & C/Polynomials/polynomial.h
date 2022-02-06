#ifndef _POLYNOMIAL
#define _POLYNOMIAL

#define false 0
#define true 1
#define bool unsigned char

typedef struct
{
    int degree;
    double *coeff;
} Polynomial;

// Create a new polynomial
Polynomial *newPolynomial(int, double *);

// Print to the console a given polynomial
void printPolynomial(Polynomial *);

// Calculate P(x)
double P(Polynomial *, double);

// Polynomials addition
Polynomial *add(Polynomial *, Polynomial *);

// Polynomials substraction
Polynomial *sub(Polynomial *, Polynomial *);

// Change the sign of a given polynomial
void changeSign(Polynomial *);

// Compare polynomials
bool compare(Polynomial *, Polynomial *);

// Calculate a polynomial's derivative
Polynomial *derivative(Polynomial *);

// Trace a polynomial's graph in an interval [a, b]
void trace(double, double);

#endif