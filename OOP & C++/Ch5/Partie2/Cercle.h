#include "../Partie1/Forme.h"
#include "../Partie1/Coordonne.h"

class Cercle : public Forme
{
private:
    Coordonne centre;
    short rayon;

public:
    Cercle(int x, int y, short col, short ray) : Forme(col)
    {
        centre.deplace(x, y);
        rayon = ray;
    }
    Cercle(const Cercle &c) : Forme(c)
    {
        centre = c.centre;
        rayon = c.rayon;
    }
    Cercle &operator=(const Cercle &c)
    {
        centre = c.centre;
        rayon = c.rayon;
    }
    void affiche()
    {
        Forme::affiche();
        centre.affiche();
        std::cout << "Rayon: " << rayon << std::endl;
    }
    void deplace(int x, int y)
    {
        centre.deplace(x, y);
    }
    int surface()
    {
        return 3 * rayon * rayon;
    }
    int perimetre()
    {
        return 2 * rayon * 3.14;
    }
};