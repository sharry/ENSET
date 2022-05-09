#include "Carre.h"

int main(int argc, char const *argv[])
{
    Carre c(10, 20, 5, 10);
    c.affiche();
    c.deplace(5, 4);
    c.affiche();
    return 0;
}
