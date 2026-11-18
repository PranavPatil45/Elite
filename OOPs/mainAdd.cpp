#include <iostream>
#include "add.h"

using namespace std;

int main()
{
    int num1 = 10, num2 = 20;
    int result = add(num1, num2);

    cout << "The sum of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}