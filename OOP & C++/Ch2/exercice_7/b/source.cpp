#include "Hasard.h"

int main()
{
    Hasard suitel(15, 5);
    suitel.affiche();
    std::cin.get();
    Hasard suite2(6, 12);
    suite2.affiche();
    return 0;
}