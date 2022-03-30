#include "Point.h"

void scene()
{
    Point u;
    u.initialiser(10, 10, 0xFF0000);
    u.afficher();
    u.deplacer(3, 2);
    u.afficher();
}

main(int argc, char const *argv[])
{
    scene();
    return 0;
}