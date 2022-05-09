#include <iostream>

class Point
{
private:
    int x, y;

public:
    Point(int abs = 0, int ord = 0) : x(abs), y(ord) {}
    friend int coincide(Point p1, Point p2);
};

int coincide(Point p1, Point p2)
{
    return (int)(p1.x == p2.x && p1.y == p2.y);
}

int main(int argc, char const *argv[])
{
    Point a(4, 0), b(4), c;
    if (coincide(a, b))
        std::cout << "a and b coincide" << std::endl;
    else
        std::cout << "a and b do not coincide" << std::endl;
    if (coincide(a, c))
        std::cout << "a and c coincide" << std::endl;
    else
        std::cout << "a and c do not coincide" << std::endl;

    std::cin.get();
    return 0;
}
