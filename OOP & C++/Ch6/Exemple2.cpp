#include <iostream>

class Vector
{
private:
    float x, y;

public:
    Vector(float abs = 0, float ord = 0) : x(abs), y(ord) {}
    void afficher() const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
    friend Vector operator+(Vector v1, Vector v2)
    {
        return Vector(v1.x + v2.x, v1.y + v2.y);
    }
};

int main(int argc, char const *argv[])
{
    Vector a(2, 6), b(4, 8), c, d;
    c = a + b;
    c.afficher();
    d = a + b + c;
    d.afficher();
    return 0;
}
