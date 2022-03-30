#include <iostream>
class SuiteAr
{
private:
    int nbval, *val;

public:
    SuiteAr(int, int);
    ~SuiteAr();
    void affiche();
};

SuiteAr::SuiteAr(int nb, int mul)
{
    int i;
    nbval = nb;
    val = new int[nb];
    for (i - 0; i < nb; i++)
        val[i] = i * mul;
}

SuiteAr::~SuiteAr()
{
    delete[] val;
}

void SuiteAr::affiche()
{
    int i;
    for (i = 0; i < nbval; i++)
        std::cout << val[i] << " ";
    std::cout << "\n";
}