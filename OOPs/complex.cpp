#include <iostream>
using namespace std;
class Complex
{
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;

        return temp;
    }

    friend ostream &operator<<(ostream &out, Complex &obj)
    {
        out << obj.real << "+" << obj.img << "i" << endl;
        return out;
    }
};
int main()
{
    Complex c1(4, 5);
    Complex c2(3, 4);
    Complex c3;

    c3 = c1 + c2;
    cout << c3;

    return 0;
}
