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

void test()
{
    std::cout << "Debut du test" << std::endl;
    Point u(3, 7);
    std::cout << "Fin du test" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "Debut du programme" << std::endl;
    Point a(1, 4);
    test();
    Point b(5, 10);
    for (int i = 0; i < 3; i++)
    {
        std::cout << "i = " << i << std::endl;
        Point(7 + i, 12 + i);
    }
    std::cout << "Fin du programme" << std::endl;
    std::cin.get();
    return 0;
}
