#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
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
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
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
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
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

    // Delete head
    if (position == 1)
    {
        // Only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node *deleteNode = head;

        head = head->next;
        temp->next = head;

        delete deleteNode;
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

    Node *deleteNode = temp->next;

    if (deleteNode == head)
    {
        cout << "Invalid position" << endl;
        return;
    }

    temp->next = deleteNode->next;

    delete deleteNode;
}

// Print Circular Linked List
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
        cout << temp->data << " -> ";
        temp = temp->next;

    } while (temp != head);

    cout << "HEAD" << endl;
}

// Main function
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