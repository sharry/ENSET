#include "Cercle.h"

int main(int argc, char const *argv[])
{
    Cercle cl(10, 20, 12, 5);
    cl.deplace(5, 2);
    cl.affiche();
    std::cin.get();
    return 0;
}
