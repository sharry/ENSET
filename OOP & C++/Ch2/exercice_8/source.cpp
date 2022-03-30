#include "Complex.h"
int main()
{
    Complex c1(1, 2);
    Complex c2(3);
    std::cout << c1.modulus() << std::endl;
    c2.print();
    return 0;
}