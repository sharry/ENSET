#include <iostream>

void test(int n = 0, float x = 2.5)
{
    std::cout << "Fonction n 1: ";
    std::cout << "n = " << n << "  x = " << x << "\n";
}
void test(float x = 4, int n = 2)
{
    std::cout << "Fonction n 2: ";
    std::cout << "n = " << n << "  x = " << x << "\n";
}

int main(int argc, char const *argv[])
{
    int i = 5;
    float r = 3.2;
    test(i, r);
    test(r, i);
    test(i);
    test(r);
    std::cin.get();
    return 0;
}

/*
    Conclusion:
        Le compilateur a choisi la bonne fonction d'après les paramètre saisies.
*/
