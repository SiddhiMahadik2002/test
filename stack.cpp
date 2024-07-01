#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(8);
    s.push(4);
    s.push(7);
    s.push(2);
    s.push(1);
    s.push(3);
    cout << s.peek() << " ";

    s.pop();
    s.pop();
    cout << s.peek() << " ";
}
