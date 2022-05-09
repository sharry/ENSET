#include "../Partie1/Coordonne.h"
#include "../Partie1/Forme.h"

class Carre : public Forme
{
private:
    short cote;
    Coordonne a;

public:
    Carre(int x, int y, short cote, short col) : Forme(col), cote(cote), a(x, y) {}
    Carre(const Carre &c) : Forme(c), cote(c.cote), a(c.a) {}
    Carre &operator=(const Carre &c)
    {
        cote = c.cote;
        a = c.a;
    }
    void affiche()
    {
        Forme::affiche();
        a.affiche();
        std::cout << "Cote: " << cote << std::endl;
    }
    void deplace(int x, int y)
    {
        a.deplace(x, y);
    }
    double surface()
    {
        return cote * cote;
    }
    double perimetre()
    {
        return 4 * cote;
    }
};