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

Point a(1, 4); // Variable globale
int main(int argc, char const *argv[])
{
    std::cout << "Debut du programme" << std::endl;
    Point b(5, 10);
    std::cout << "Fin du programme" << std::endl;
    std::cin.get();
    return 0;
}
