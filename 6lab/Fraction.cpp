#include "Fraction.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

Fraction::Fraction(int num, int den)
{
    if (den == 0)
    {
        throw std::invalid_argument("The denominator cannot be zero.");
    }

    numerator = num;
    denominator = den;
    reduce();
}

Fraction::Fraction(const Fraction& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
    reduce();
}

void Fraction::reduce()
{
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    int a = std::abs(numerator);
    int b = std::abs(denominator);

    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    if (a != 0)
    {
        numerator /= a;
        denominator /= a;
    }
}

int Fraction::getNumerator() const
{
    return numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

Fraction Fraction::add(const Fraction& other) const
{
    Fraction result(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
    result.reduce();
    return result;
}

Fraction Fraction::multiply(const Fraction& other) const
{
    Fraction result(numerator * other.numerator,
                    denominator * other.denominator);
    result.reduce();
    return result;
}

Fraction Fraction::divide(const Fraction& other) const
{
    if (other.numerator == 0)
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    Fraction result(numerator * other.denominator,
                    denominator * other.numerator);
    result.reduce();
    return result;
}

void Fraction::print() const
{
    if (denominator == 1)
    {
        std::cout << numerator;
    }
    else
    {
        std::cout << numerator << '/' << denominator;
    }
}
