#include <iostream>

class Point
{
protected:
    int x, y;

public:
    void init(int abs, int ord)
    {
        x = abs;
        y = ord;
    }
    void deplacer(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
    void afficher() const
    {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
};

class pointcol : public Point
{
private:
    short couleur;

public:
    void colore(short c)
    {
        couleur = c;
    }
    // Redefinition de la methode afficher
    void afficher() const
    {
        std::cout << "(" << x << "," << y << "," << couleur << ")" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    pointcol p;
    p.init(10, 20);
    p.colore(0xffff);
    p.afficher();
    p.deplacer(2, 4);
    p.afficher();
    return 0;
}
