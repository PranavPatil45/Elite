#include "LQueue.h"

using namespace std;

int main()
{
    // Instantiate a Linear Queue with a max capacity of 5
    Queue myQueue(5);

    cout << "=== Enqueue Operations (FIFO) ===" << endl;
    myQueue.enqueue(100);
    myQueue.enqueue(200);
    myQueue.enqueue(300);

    cout << "\n=== Inspecting Queue State ===" << endl;
    cout << "Front element: " << myQueue.peekFront() << endl;
    cout << "Current queue size: " << myQueue.size() << endl;

    cout << "\n=== Dequeue Operations ===" << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    cout << "\n=== Final State ===" << endl;
    cout << "Front element now: " << myQueue.peekFront() << endl;
    cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}