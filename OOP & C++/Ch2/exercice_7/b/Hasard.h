#include <iostream>
#include <stdlib.h>
class Hasard
{
private:
    int nbval;
    int *val;

public:
    Hasard(int, int);
    ~Hasard();
    void affiche();
};
Hasard::Hasard(int nb, int max)
{
    int i;
    val = new int[nbval = nb];
    for (i = 0; i < nb; i++)
        val[i] = (double)(rand()) / RAND_MAX * max;
}
Hasard::~Hasard()
{
    delete[] val;
}
void Hasard::affiche()
{
    int i;
    for (i = 0; i < nbval; i++)
        std::cout << val[i] << " ";
    std::cout << "\n";
}