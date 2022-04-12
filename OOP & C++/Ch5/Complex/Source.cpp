#include "Complex.cpp"
#define PI 3.14159265358979323846
int main(int argc, char const *argv[])
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;
    Complex c7 = -c1;
    Complex c8 = c1.conjugate();
    Complex c9 = c1.polar(5.0, PI / 2.0);
    Complex c10 = c1.polar(5.0);
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
    std::cout << c5 << std::endl;
    std::cout << c6 << std::endl;
    std::cout << c7 << std::endl;
    std::cout << c8 << std::endl;
    std::cout << c9 << std::endl;
    std::cout << c10 << std::endl;
    return 0;
}
