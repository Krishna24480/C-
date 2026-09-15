#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = tail->next;
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void print(Node* head){
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    print(head);

    int Length = getLength(head);

    cout << "Length Of DLL is: " << Length << endl;

    insertAtHead(head, 4);
    insertAtHead(head, 3);

    print(head);

    cout << "Length Of DLL is: " << Length << endl;

    insertAtTail(tail, 6);
    insertAtTail(tail, 7);

    print(head);

    cout << "Length Of DLL is: " << Length << endl;

    return 0;
}