#include "Stack.h"

using namespace std;

int main()
{

    Stack myStack(5);

    cout << "=== Pushing Elements ===" << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "\n=== Inspecting Stack State ===" << endl;
    cout << "Top element (peek): " << myStack.peek() << endl;
    cout << "Current stack size: " << myStack.size() << endl;

    cout << "\n=== Popping Elements ===" << endl;
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    cout << "\n=== Final State ===" << endl;
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top element now: " << myStack.peek() << endl;

    return 0;
}