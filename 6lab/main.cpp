#include <iostream>
#include <exception>
#include "Fraction.h"

int main()
{
    int num1, den1, num2, den2;

    std::cout << "Enter the numerator and denominator of the first fraction: ";
    std::cin >> num1 >> den1;

    std::cout << "Enter the numerator and denominator of the second fraction: ";
    std::cin >> num2 >> den2;

    try
    {
        Fraction first(num1, den1);
        Fraction second(num2, den2);
        Fraction copy(first);

        std::cout << "First fraction: ";
        first.print();

        std::cout << "\nSecond fraction: ";
        second.print();

        std::cout << "\nCopy of the first fraction: ";
        copy.print();

        std::cout << "\nAddition: ";
        first.add(second).print();

        std::cout << "\nMultiplication: ";
        first.multiply(second).print();

        std::cout << "\nDivision: ";
        first.divide(second).print();

        std::cout << '\n';
    }
    catch (const std::exception& error)
    {
        std::cout << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
