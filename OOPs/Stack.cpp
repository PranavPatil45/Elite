#include "Stack.h"

using namespace std;

Stack::Stack(int size)
{
    capacity = size;
    arr = new int[capacity];
    topIndex = -1;
}

Stack::~Stack()
{
    delete[] arr;
}

void Stack::push(int element)
{
    if (isFull())
    {
        cout << "Stack Overflow! Cannot push " << element << endl;
        return;
    }
    arr[++topIndex] = element;
    cout << "Pushed: " << element << endl;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow! Stack is empty." << endl;
        return -1;
    }
    return arr[topIndex--];
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return arr[topIndex];
}

bool Stack::isEmpty()
{
    return topIndex == -1;
}

bool Stack::isFull()
{
    return topIndex == capacity - 1;
}

int Stack::size()
{
    return topIndex + 1;
}