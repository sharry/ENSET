#include <iostream>
#include <stdlib.h>
class Hasard
{
private:
    int val[10];

public:
    Hasard(int);
    void affiche();
};
Hasard::Hasard(int max)
{
    int i;
    for (i = 0; i < 10; i++)
        val[i] = (double)(rand()) / RAND_MAX * max;
}
void Hasard::affiche()
{
    int i;
    for (i = 0; i < 10; i++)
        std::cout << val[i] << " ";
    std::cout << "\n";
}