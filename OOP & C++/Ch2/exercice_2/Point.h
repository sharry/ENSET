#include <iostream>

class Point
{
private:
    int x, y, color;

public:
    void initialiser(int, int, int);
    void deplacer(int, int);
    void afficher();
    void effacer();
};

void Point::initialiser(int x, int y, int color)
{
    this->x = x;
    this->y = y;
    this->color = color;
}
void Point::deplacer(int x, int y)
{
    this->x += x;
    this->y += y;
}
void Point::afficher()
{
    std::cout << "x: " << this->x << " y: " << this->y << " color: " << this->color << std::endl;
}
void Point::effacer()
{
    this->x = 0;
    this->y = 0;
    this->color = 0x000000;
}