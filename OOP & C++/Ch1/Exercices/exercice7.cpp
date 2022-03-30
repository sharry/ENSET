#include <iostream>
#include <assert.h>

void affiche(float x, int n = 0)
{
    assert(n >= 0);
    if (n == 0)
        std::cout << x << "^0 = 1\n";
    else
    {
        float ret = 1;
        while (n--)
            ret *= x;
        std::cout << x << "^" << n << " = " << ret << "\n";
    }
}
void affiche(int n, float x = 0)
{
    assert(n >= 0);
    if (n == 0)
        std::cout << x << "^0 = 1\n";
    else
    {
        float ret = 1;
        while (n--)
            ret *= x;
        std::cout << x << "^" << n << " = " << ret << "\n";
    }
}
int main(int argc, char const *argv[])
{
    affiche(5.0, 3);
    affiche(5, 3.0);
    affiche(3);
    // affiche(3.0); -> err
    return 0;
}
