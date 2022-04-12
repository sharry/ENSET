#include <iostream>

class Point
{
private:
    int x, y;

public:
    Point(int, int);
    ~Point();
};

Point::Point(int a, int b) : x(a), y(b)
{
    std::cout << "Constructeur du Point (" << x << ", " << y << ')' << std::endl;
    std::cout << "Son adresse (" << this << ')' << std::endl;
}

Point::~Point()
{
    std::cout << "Destructeur du Point (" << x << ", " << y << ')' << std::endl;
    std::cout << "Son adresse (" << this << ')' << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "Debut du programme\n";
    Point a(3, 7);
    Point b = a;
    std::cout << "Fin du programme\n";
    return 0;
}
