#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    int numerator;
    int denominator;

    void reduce();

public:
    Fraction() = delete;

    Fraction(int num, int den);
    Fraction(const Fraction& other);

    int getNumerator() const;
    int getDenominator() const;

    Fraction add(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;

    void print() const;
};

#endif
