#include <iostream>
struct essai
{
    int n;
    float x;
};

void remise_a_zero(essai e)
{
    e.n = 0;
    e.x = 0.0;
}
void remise_a_zero(essai *e)
{
    e->n = 0;
    e->x = 0.0;
}

int main(int argc, char const *argv[])
{
    essai e;
    e.n = 6;
    e.x = 3.3;
    std::cout << "Avant:\ne.n = " << e.n << "\ne.x = " << e.x;
    remise_a_zero(e);
    std::cout << "\nPar valeur:\ne.n = " << e.n << "\ne.x = " << e.x;
    remise_a_zero(&e);
    std::cout << "\nPar adresse:\ne.n = " << e.n << "\ne.x = " << e.x;
    return 0;
}
