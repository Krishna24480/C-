#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Insert at Head
void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    Node *tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;

    head = newNode;
}

// Insert at Tail
void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    Node *tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;
}

// Insert at Position
void insertAtPosition(Node *&head, int value, int position)
{
    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1)
    {
        insertAtHead(head, value);
        return;
    }

    if (head == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position" << endl;
            return;
        }
    }

    Node *newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at Position
void deleteAtPosition(Node *&head, int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // Delete Head
    if (position == 1)
    {
        // Only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *tail = head->prev;
        Node *deleteNode = head;

        head = head->next;

        head->prev = tail;
        tail->next = head;

        delete deleteNode;
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position" << endl;
            return;
        }
    }

    Node *deleteNode = temp;

    deleteNode->prev->next = deleteNode->next;
    deleteNode->next->prev = deleteNode->prev;

    delete deleteNode;
}

// Print Doubly Circular Linked List
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;

    } while (temp != head);

    cout << "HEAD" << endl;
}

// Main Function
int main()
{
    Node *head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);

    insertAtTail(head, 30);
    insertAtTail(head, 40);

    insertAtPosition(head, 25, 3);

    print(head);

    deleteAtPosition(head, 3);

    print(head);

    return 0;
}