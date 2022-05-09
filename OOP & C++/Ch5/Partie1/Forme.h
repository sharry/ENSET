#include <iostream>

class Forme
{
private:
    short couleur;

public:
    Forme(short c = 1)
    {
        couleur = c;
    }
    Forme(const Forme &f)
    {
        couleur = f.couleur;
    }
    void affiche()
    {
        std::cout << "Couleur: " << couleur << std::endl;
    }
    Forme &operator=(const Forme &f)
    {
        couleur = f.couleur;
        return *this;
    }
};
