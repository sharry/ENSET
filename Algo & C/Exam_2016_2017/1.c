// Exercice 1 | Développement limité de la fonction arctan(x) o(2n+3)
#include <stdio.h>
#include <math.h>

// ₖ₌₀Σⁿ[(-1)ᵏ(x²ᵏ⁺¹/2k+1)] + o(x²ⁿ⁺³)
double arctan(double x, int n)
{
    double out = 0;
    int k = 0, end = 2 * n + 3, power = 0;
    while (power < end)
    {
        power = 2 * k + 1;
        out += pow(-1, k) * (pow(x, power) / power);
        k++;
    }
    return out;
}
// Test
int main(int argc, char const *argv[])
{
    printf("arctan(2) = %lf\n\n", arctan(/*x =*/4, /*n =*/4));
    return 0;
}