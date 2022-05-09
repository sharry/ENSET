#include "Rectangle.h"

int main(int argc, char const *argv[])
{
    Rectangle r(10, 20, 30, 40, 11);
    r.affiche();
    r.deplace(5, 4);
    r.affiche();
    return 0;
}
