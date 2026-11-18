
#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    Stack(int size = 10);
    ~Stack();

    void push(int element);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
};
