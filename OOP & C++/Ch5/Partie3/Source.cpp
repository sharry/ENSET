#include "Triangle.h"

int main(int argc, char const *argv[])
{
    Triangle t(10, 20, 30, 40, 50, 50, 11);
    t.affiche();
    t.deplace(5, 4);
    t.affiche();
    return 0;
}
