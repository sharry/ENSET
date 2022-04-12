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

void fct(Point *adp)
{
    std::cout << "Debut de la fonction\n";
    delete adp;
    std::cout << "Fin de la fonction\n";
}

int main(int argc, char const *argv[])
{
    Point *adr;
    std::cout << "Debut du programme\n";
    adr = new Point(3, 7);
    fct(adr);
    delete adr;
    std::cout << "Fin du programme\n";
    std::cin.get();
    return 0;
}
