#include <iostream>

void essai(float x, char c, int n = 0)
{
    std::cout << "Fontion N1: x = " << x << " c = " << c << " n = " << n << "\n";
}

void essai(float x, int n)
{
    std::cout << "Fontion N2 : x = " << x << " n = " << n << "\n";
}

int main(int argc, char const *argv[])
{
    char l = 'z';
    int u = 4;
    float y = 2.0;

    essai(y, l, u);
    essai(y, l);
    essai(y, u);
    essai(u, u);
    essai(u, l);
    essai(y, y, u);

    std::cin.get();
}

/*
    Conclusion:
        cout imprime la valeur du variable respectivement au son type.
*/