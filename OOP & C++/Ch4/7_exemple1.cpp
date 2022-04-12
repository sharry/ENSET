#include <iostream>

class Point
{
private:
	int x, y;

public:
	Point(int, int);
	Point(const Point &);
	Point symetrique();
	void affiche();
	~Point();
};

Point::Point(int abs = 0, int ord = 0)
{
	x = abs;
	y = ord;
	std::cout << "Constructeur de Point (" << x << ", " << y << ") "
			  << "d'adresse " << this << std::endl;
}

Point::Point(const Point &p)
{
	x = p.x;
	y = p.y;
	std::cout << "Constructeur de copie de Point (" << x << ", " << y << ") "
			  << "d'adresse " << this << std::endl;
}

Point Point::symetrique()
{
	Point p;
	std::cout << "********************************\n";
	p.x = -x;
	p.y = -y;
	std::cout << "################################\n";
	return p;
}

Point::~Point()
{
	std::cout << "Destructeur de Point (" << x << ", " << y << ") "
			  << "d'adresse " << this << std::endl;
}

void Point::affiche()
{
	std::cout << "Point (" << x << ", " << y << ") " << std::endl;
}

int main(int argc, char const *argv[])
{
	std::cout << "Debut du programme\n";
	Point a(1, 4), b;
	std::cout << "Avant le symetrique\n";
	b = a.symetrique();
	b.affiche();
	std::cout << "Apres le symetrique\n";
	return 0;
}