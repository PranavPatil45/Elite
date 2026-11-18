

class Stack
{
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int top;

public:
    Stack();
    int push(int val);
    int pop(int &val);
    int peek(int &val);
    bool isEmpty() const;
    bool isFull() const;
};
