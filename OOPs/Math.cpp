#include <iostream>
#include <stdexcept>
#include "Math.h"

int Math::add(int a, int b)
{
    return a + b;
}

int Math::sub(int a, int b)
{
    return a - b;
}

int Math::mul(int a, int b)
{
    return a * b;
}

double Math::div(int a, int b)
{
    if (b == 0)
    {
        std::cerr << "Error: Division by zero is undefined.\n";
        return 0.0;
    }
    return static_cast<double>(a) / b;
}