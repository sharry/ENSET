#include "../Partie1/Coordonne.h"
#include "../Partie1/Forme.h"

class Rectangle : public Forme
{
protected:
    Coordonne a, b;

public:
    Rectangle(int x1, int y1, int x2, int y2, short col) : Forme(col)
    {
        a.deplace(x1, y1);
        b.deplace(x2, y2);
    }
    Rectangle(const Rectangle &r) : Forme(r)
    {
        a = r.a;
        b = r.b;
    }
    Rectangle &operator=(const Rectangle &r)
    {
        a = r.a;
        b = r.b;
    }
    void affiche()
    {
        Forme::affiche();
        a.affiche();
        b.affiche();
    }
    void deplace(int x, int y)
    {
        a.deplace(x, y);
        b.deplace(x, y);
    }
    double surface()
    {
        return (b.getX() - a.getX()) * (b.getY() - a.getY());
    }
    double perimetre()
    {
        return 2 * (b.getX() - a.getX()) + 2 * (b.getY() - a.getY());
    }
};