#include <iostream>
#include <cmath>

class Complex
{
private:
    double _real;
    double _imag;

public:
    // Constructors
    Complex(double, double = 0.0);
    Complex();
    Complex(const Complex &);
    ~Complex();

    // Real part
    double real() const;
    // Imaginary part
    double imag() const;
    // Complex conjugate
    Complex conjugate() const;
    // Complex norm
    double norm() const;
    // Complex argument
    double arg() const;
    // Complex from polar coordinates
    Complex polar(double, double = 0.0);

    // Operator overloading

    // Assignment operator
    Complex &operator=(const Complex &);
    // Addition operator
    Complex operator+(const Complex &) const;
    friend Complex operator+(double, const Complex &);
    friend Complex operator+(const Complex &, double);
    // Subtraction operator
    Complex operator-(const Complex &) const;
    friend Complex operator-(double, const Complex &);
    friend Complex operator-(const Complex &, double);
    // Multiplication operator
    Complex operator*(const Complex &) const;
    friend Complex operator*(double, const Complex &);
    friend Complex operator*(const Complex &, double);
    // Division operator
    Complex operator/(const Complex &) const;
    friend Complex operator/(double, const Complex &);
    friend Complex operator/(const Complex &, double);
    // Comparison operators
    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;
    // Inversion operator
    Complex operator-() const;
    // IO stream operators
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);
};