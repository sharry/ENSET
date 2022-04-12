#include "Complex.h"

Complex::Complex(double real, double imag)
{
    _real = real;
    _imag = imag;
}
Complex::Complex()
{
    _real = 0.0;
    _imag = 0.0;
}
Complex::~Complex() {}
Complex::Complex(const Complex &other)
{
    _real = other._real;
    _imag = other._imag;
}
double Complex::real() const
{
    return _real;
}
double Complex::imag() const
{
    return _imag;
}
Complex Complex::conjugate() const
{
    return Complex(_real, -_imag);
}
double Complex::norm() const
{
    return sqrt(_real * _real + _imag * _imag);
}
double Complex::arg() const
{
    return atan2(_imag, _real);
}
Complex Complex::polar(double r, double theta)
{
    return Complex(r * cos(theta), r * sin(theta));
}
Complex &Complex::operator=(const Complex &other)
{
    _real = other._real;
    _imag = other._imag;
    return *this;
}
Complex Complex::operator+(const Complex &other) const
{
    return Complex(_real + other._real, _imag + other._imag);
}
Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs._real, rhs._imag);
}
Complex operator+(const Complex &rhs, double lhs)
{
    return Complex(lhs + rhs._real, rhs._imag);
}
Complex Complex::operator-(const Complex &other) const
{
    return Complex(_real - other._real, _imag - other._imag);
}
Complex operator-(double lhs, const Complex &rhs)
{
    return Complex(lhs - rhs._real, -rhs._imag);
}
Complex operator-(const Complex &rhs, double lhs)
{
    return Complex(rhs._real - lhs, rhs._imag);
}
Complex Complex::operator*(const Complex &other) const
{
    return Complex(_real * other._real - _imag * other._imag, _real * other._imag + _imag * other._real);
}
Complex operator*(double lhs, const Complex &rhs)
{
    return Complex(lhs * rhs._real, lhs * rhs._imag);
}
Complex operator*(const Complex &rhs, double lhs)
{
    return Complex(lhs * rhs._real, lhs * rhs._imag);
}
Complex Complex::operator/(const Complex &other) const
{
    double denom = other._real * other._real + other._imag * other._imag;
    return Complex((_real * other._real + _imag * other._imag) / denom, (_imag * other._real - _real * other._imag) / denom);
}
Complex operator/(double lhs, const Complex &rhs)
{
    double denom = rhs._real * rhs._real + rhs._imag * rhs._imag;
    return Complex((lhs * rhs._real + rhs._imag * 0.0) / denom, (lhs * rhs._imag - rhs._real * 0.0) / denom);
}
Complex operator/(const Complex &rhs, double lhs)
{
    double denom = rhs._real * rhs._real + rhs._imag * rhs._imag;
    return Complex((rhs._real * lhs + rhs._imag * 0.0) / denom, (rhs._imag * lhs - rhs._real * 0.0) / denom);
}
bool Complex::operator==(const Complex &other) const
{
    return _real == other._real && _imag == other._imag;
}
bool Complex::operator!=(const Complex &other) const
{
    return _real != other._real || _imag != other._imag;
}
Complex Complex::operator-() const
{
    return Complex(-_real, -_imag);
}
std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << c._real;
    if (c._imag >= 0.0)
        os << "+";
    os << c._imag << "i";
    return os;
}
std::istream &operator>>(std::istream &is, Complex &c)
{
    is >> c._real >> c._imag;
    return is;
}