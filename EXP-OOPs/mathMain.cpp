#include <iostream>
#include "math.h"

using namespace std;

int main()
{
     Math obj;

     int res_add = obj.add(10, 5);
     int res_sub = obj.sub(10, 5);
     int res_mul = obj.mul(10, 5);
     int res_div = obj.div(10, 5);

     cout << "Addition : " << res_add << endl;
     cout << "Subtraction : " << res_sub << endl;
     cout << "Multiplication : " << res_mul << endl;
     cout << "Division : " << res_div << endl;

     return 0;
}