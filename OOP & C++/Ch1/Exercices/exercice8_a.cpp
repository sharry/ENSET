#include <iostream>

void echange(int a, int b)
{
    int tampon;
    tampon = b;
    b = a;
    a = tampon;
    std::cout << "Pendant l'echange: a = " << a << " b = " << b << "\n";
}
int main()
{
    int u = 5, v = 3;
    std::cout << "Avant echange: u = " << u << " v = " << v << "\n";
    echange(u, v);
    std::cout << "Apres echange: u = " << u << " v = " << v << "\n";
    std::cin.get();
    return 0;
}