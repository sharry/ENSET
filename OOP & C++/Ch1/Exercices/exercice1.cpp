#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    float x;
    printf("donnez un entier et un flottant\n");
    scanf("%d %e", &n, &x);
    printf("le produit de %d par %e\n est %e\n", n, x, n * x);
    return 0;
}
