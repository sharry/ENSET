#include "Point.h"
int main(int argc, char const *argv[])
{
    Point p;
    p.initialiser(10, 10, 0xFF0000);
    p.deplacer(3, 0);
    // p.effacer();
    p.afficher();
    return 0;
}