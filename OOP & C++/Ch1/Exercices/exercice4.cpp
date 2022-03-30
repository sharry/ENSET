#include <iostream>

float puissance(int x, int n = 4)
{
    if (n == 0)
        return 1;
    else if (n < 0)
    {
        n = n * -1;
        int ret = 1;
        while (n--)
            ret *= x;
        return 1 / (float)ret;
    }
    else
    {
        int ret = 1;
        while (n--)
            ret *= x;
        return ret;
    }
}
int main(int argc, char const *argv[])
{
    int x, n;
    std::cout << "Calcul de x^n\n";
    std::cout << "Entrer le x: ";
    std::cin >> x;
    std::cout << "Entrer le n: ";
    std::cin >> n;
    std::cout << x << "^" << n << " = " << puissance(x, n);
    std::cin.get();
    return 0;
}

/*
    Conclusion:
        Lors de la saisie d'un nombre avec virgule, le program ne marche pas comme il est prévu.
*/
