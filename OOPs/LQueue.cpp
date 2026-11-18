#include <iostream>
#include "LQueue.h"

using namespace std;

// Constructor: Initializes internal memory and indices
Queue::Queue(int size)
{
    capacity = size;
    arr = new int[capacity];
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

// Destructor: Cleans up dynamically allocated array
Queue::~Queue()
{
    delete[] arr;
}

// Insert an element at the rear of the queue
void Queue::enqueue(int element)
{
    if (isFull())
    {
        cout << "Queue Overflow! Cannot enqueue " << element << endl;
        return;
    }
    rearIndex++;
    arr[rearIndex] = element;
    count++;
    cout << "Enqueued: " << element << endl;
}

// Remove and return the front element from the queue
int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow! Queue is empty." << endl;
        return -1;
    }
    int value = arr[frontIndex];
    frontIndex++;
    count--;
    return value;
}

// Inspect the front element without removing it
int Queue::peekFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return arr[frontIndex];
}

// Utility functions
bool Queue::isEmpty()
{
    return count == 0;
}

bool Queue::isFull()
{
    return rearIndex == capacity - 1;
}

int Queue::size()
{
    return count;
}