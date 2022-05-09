#include "../Partie1/Coordonne.h"
#include "../Partie1/Forme.h"

class Triangle : public Forme
{
private:
    Coordonne a, b, c;

public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3, short col) : Forme(col)
    {
        a.deplace(x1, y1);
        b.deplace(x2, y2);
        c.deplace(x3, y3);
    }
    Triangle(const Triangle &t) : Forme(t)
    {
        a = t.a;
        b = t.b;
        c = t.c;
    }
    Triangle &operator=(const Triangle &t)
    {
        a = t.a;
        b = t.b;
        c = t.c;
    }
    void affiche()
    {
        Forme::affiche();
        a.affiche();
        b.affiche();
        c.affiche();
    }
    void deplace(int x, int y)
    {
        a.deplace(x, y);
        b.deplace(x, y);
        c.deplace(x, y);
    }
    double surface()
    {
        int x = (b.getX() - a.getX()) * (c.getY() - a.getY());
        int y = (c.getX() - b.getX()) * (a.getY() - b.getY());
        int z = (a.getX() - c.getX()) * (b.getY() - c.getY());
        return abs(x + y + z) / 2;
    }
    double perimetre()
    {
        return a.distance(b) + b.distance(c) + c.distance(a);
    }
};