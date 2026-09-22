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

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
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
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool IsEmpty()
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

    Stack st(5);

    st.push(7);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.push(7);

    cout << st.peek() << endl;

    if (st.IsEmpty())
    {
        cout << "stack is Empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    
    
    /*
    stack<int> s;

    s.push(66);

    s.push(77);

    s.pop();

    if (s.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }

    cout <<"Top Element: "<< s.top() << endl;

    cout <<"Size Of Stack"<< s.size() << endl;
    */

    return 0;
}