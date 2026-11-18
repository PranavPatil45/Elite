#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack s;
    int val = 0;

    s.push(10);
    s.push(20);
    cout << "Pushed 10 and 20 into the stack.\n";

    if (s.peek(val) == 0)
    {
        cout << "Top element: " << val << "\n";
    }

    if (s.pop(val) == 0)
    {
        cout << "Popped: " << val << "\n";
    }

    if (s.pop(val) == 0)
    {
        cout << "Popped: " << val << "\n";
    }

    return 0;
}