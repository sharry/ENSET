#include <iostream>

int main(int argc, char const *argv[])
{
    int n;
    char tc[30], c;
    float x;
    std::cout << "Saisir un entier: ";
    std::cin >> n;
    std::cout << "Saisir un reel: ";
    std::cin >> x;
    std::cout << "Saisir une phrase: ";
    std::cin >> tc;
    std::cout << "Affichage:\n"
              << n << "\n"
              << x << "\n"
              << tc << "\n"
              << c;
    return 0;
    std::cin.get();
}

/*
    Conclusion:
        'cin' et 'cout' marchent avec n'importe quel type
*/
