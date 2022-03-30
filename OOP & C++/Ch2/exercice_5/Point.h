#include <iostream>

class Point
{
private:
    int x, y, color;

public:
    Point(int, int);
    void deplacer(int, int);
    void afficher();
    ~Point();
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
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
Point::~Point()
{
    this->x = 0;
    this->y = 0;
    this->color = 0x000000;
    this->afficher();
}