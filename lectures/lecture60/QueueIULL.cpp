// Queue Implemtation Using Array
#include <iostream>
using namespace std;

class Queue
{

    // Node of Linked List
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int x)
        {
            data = x;
            next = nullptr;
        }
    };

    Node *frontNode;
    Node *rearNode;
    int count;

public:
    // Constructor
    Queue()
    {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    // Insert element
    void push(int x)
    {
        Node *newNode = new Node(x);

        // If queue is empty
        if (isEmpty())
        {
            frontNode = newNode;
            rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }

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

        Node *temp = frontNode;

        frontNode = frontNode->next;

        delete temp;

        count--;

        // If queue becomes empty
        if (frontNode == nullptr)
        {
            rearNode = nullptr;
        }
    }

    // Return front element
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return frontNode->data;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return frontNode == nullptr;
    }

    // Return size of queue
    int size()
    {
        return count;
    }

    // Destructor
    ~Queue()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{

    Queue q;

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
    q.pop();

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