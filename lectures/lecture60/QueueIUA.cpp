//Queue Implemtation Using Array
#include <iostream>
using namespace std;

class Queue
{

    int *arr;
    int n;
    int frontIndex;
    int rear;
    int count;

public:
    // Constructor
    Queue(int size)
    {
        n = size;
        arr = new int[n];

        frontIndex = 0;
        rear = 0;
        count = 0;
    }

    // Insert element
    void push(int x)
    {

        if (count == n)
        {
            cout << "Queue is full" << endl;
            return;
        }

        arr[rear] = x;
        rear++;

        count++;
    }

    // Remove element
    void pop()
    {

        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        frontIndex++;

        count--;
    }

    // Return front element
    int front()
    {

        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[frontIndex];
    }

    // Check if queue is empty
    bool isEmpty()
    {

        return count == 0;
    }

    // Return size of queue
    int size()
    {

        return count;
    }

    // Destructor
    ~Queue()
    {

        delete[] arr;
    }
};

int main()
{

    int n = 10;

    Queue q(n);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

     if (q.isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not Empty" << endl;
    };

    return 0;
}