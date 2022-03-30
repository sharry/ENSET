#include <iostream>
struct complexe
{
    double reel, im;
};

void affiche(int);
void affiche(double);
void affiche(complexe);

int main(void)
{
    int a = 5;
    double d = 0.0;
    complexe c = {1.0, -1.0};
    affiche(a); // Appel la fonction (1)
    affiche(d); // Appel la fonction (2)
    affiche(c); // Appel la fonction (3)
}

void affiche(int i)
{
    std::cout << "TYPE de variable(int) : " << std::endl;
    std::cout << "Valeur : " << i << std::endl;
}
void affiche(double d)
{
    std::cout << "TYPE de variable (double) :" << std::endl;
    std::cout << "Valeur : " << d << std::endl;
}
void affiche(complexe c)
{
    std::cout << "TYPE de variable (complexe) :" << std::endl;
    std::cout << "Valeur : " << c.reel << std::endl;
    std::cout << "Valeur : " << c.im << std::endl;
}