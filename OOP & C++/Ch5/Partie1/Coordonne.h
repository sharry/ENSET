#include <iostream>
#include <cmath>

class Coordonne
{
private:
    int x, y;

public:
    Coordonne(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
    void deplace(int a, int b)
    {
        x += a;
        y += b;
    }
    void affiche()
    {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int distance(Coordonne c)
    {
        return sqrt((x - c.getX()) * (x - c.getX()) + (y - c.getY()) * (y - c.getY()));
    }
};