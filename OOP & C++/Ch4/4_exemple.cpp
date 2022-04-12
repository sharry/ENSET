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
}

Point::~Point()
{
    std::cout << "Destructeur du Point (" << x << ", " << y << ')' << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "Debut du programme" << std::endl;
    Point a(0, 0);
    a = Point(1, 2);
    a = Point(3, 5);
    std::cout << "Fin du programme" << std::endl;
    std::cin.get();
    return 0;
}
