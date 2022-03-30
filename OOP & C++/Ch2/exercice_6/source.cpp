#include "SuiteAr.h"

int main(int argc, char const *argv[])
{
    SuiteAr suitel(10, 4);
    suitel.affiche();
    std::cin.get();
    SuiteAr suite2(6, 8);
    suite2.affiche();
    std::cin.get();
    return 0;
}
