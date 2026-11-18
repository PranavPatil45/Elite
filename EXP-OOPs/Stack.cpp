#include "Stack.h"

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty() const
{
    return top == -1;
}

bool Stack::isFull() const
{
    return top == MAX_SIZE - 1;
}

int Stack::push(int val)
{
    if (isFull())
    {
        return -1;
    }
    arr[++top] = val;
    return 0;
}

int Stack::pop(int &val)
{
    if (isEmpty())
    {
        return -1;
    }
    val = arr[top--];
    return 0;
}

int Stack::peek(int &val)
{
    if (isEmpty())
    {
        return -1;
    }
    val = arr[top];
    return 0;
}