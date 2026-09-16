#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is Free: " << value << endl;
    }
};

void deleteNode(Node *&tail, int element, int d)
{
   
}

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void Print(Node *&tail)
{
    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    Print(tail);

    insertNode(tail, 3, 5);
    Print(tail);

    insertNode(tail, 5, 7);
    Print(tail);

    insertNode(tail, 7, 11);
    Print(tail);

    insertNode(tail, 7, 9);
    Print(tail);

    cout << "tail is: " << tail->data << endl;

    return 0;
}