
#include <iostream>

using namespace std;

class Queue
{
private:
    int *arr;       // Dynamic array to store queue elements
    int capacity;   // Maximum size of the queue
    int frontIndex; // Index pointing to the front element
    int rearIndex;  // Index pointing to the last inserted element
    int count;      // Current number of elements in queue

public:
    Queue(int size = 10);
    ~Queue();

    void enqueue(int element);
    int dequeue();
    int peekFront();
    bool isEmpty();
    bool isFull();
    int size();
};
