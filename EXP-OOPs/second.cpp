#include <iostream>
using namespace std;

void add()
{
    cout << "Addition = " << 10 + 20 << endl;
}

void add(int a)
{
    cout << "Addition = " << a + 20 << endl;
}

void add(int a, int b)
{
    cout << "Addition = " << a + b << endl;
}

void add(int a, int b, int c)
{
    cout << "Addition = " << a + b + c << endl;
}

void add(int *p, int arr[])
{
    cout << "Addition = " << *p + arr[0] + arr[1] << endl;
}

int main()
{
    int a = 10, b = 20, c = 30;
    int arr[2] = {20, 30};

    add();
    add(a);
    add(a, b);
    add(a, b, c);
    add(&a, arr);

    return 0;
}