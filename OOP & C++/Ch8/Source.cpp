#include <iostream>

class Point
{
protected:
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        std::cout << "Construction de Point ";
        Afficher();
    }
    ~Point()
    {
        std::cout << "Destruction de Point ";
        Afficher();
    }
    void Afficher() const
    {
        std::cout << "Point (" << x << ", " << y << ")\n";
    }
};

class Color
{
protected:
    short color;

public:
    Color(short color)
    {
        this->color = color;
        std::cout << "Construction de Color ";
    }
    ~Color()
    {
        std::cout << "Destruction de Color ";
    }
    void Afficher() const
    {
        std::cout << "Color " << color << "\n";
    }
};

class PointCol : public Point, public Color
{
public:
    PointCol(int x, int y, short color) : Point(x, y), Color(color)
    {
        std::cout << "Construction de PointCol ";
    }
    ~PointCol()
    {
        std::cout << "Destruction de PointCol ";
    }
    void Afficher() const
    {
        std::cout << "PointCol (" << x << ", " << y << ", " << color << ")\n";
    }
};

int main(int argc, char const *argv[])
{
    PointCol p1(3, 9, 2);
    std::cout << "-----------------------\n";
    p1.Afficher();
    std::cout << "-----------------------\n";
    p1.Point::Afficher();
    std::cout << "-----------------------\n";
    p1.Color::Afficher();
    std::cout << "-----------------------\n";
    return 0;
}
