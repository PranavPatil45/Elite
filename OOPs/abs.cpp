#include <iostream>
#include "Math.h"

int main()
{
    Math mathObj;

    int x = 20;
    int y = 4;

    std::cout << "=== Math Operations ===" << std::endl;
    std::cout << x << " + " << y << " = " << mathObj.add(x, y) << std::endl;
    std::cout << x << " - " << y << " = " << mathObj.sub(x, y) << std::endl;
    std::cout << x << " * " << y << " = " << mathObj.mul(x, y) << std::endl;
    std::cout << x << " / " << y << " = " << mathObj.div(x, y) << std::endl;

    std::cout << "\nTesting division by zero:\n";
    mathObj.div(x, 0);

    return 0;
}