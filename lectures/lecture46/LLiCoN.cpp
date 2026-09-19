//Check that Link List is Circular or not

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

// Insert at Tail
void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Make Linked List Circular
void makeCircular(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
}

// Check whether Linked List is Circular
bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

// Print normal Linked List
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Print Circular Linked List
void printCircular(Node *head)
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

// Main Function
int main()
{
    // -------------------------------
    // Example 1: Circular Linked List
    // -------------------------------

    Node *head1 = NULL;

    insertAtTail(head1, 10);
    insertAtTail(head1, 20);
    insertAtTail(head1, 30);
    insertAtTail(head1, 40);

    // Make it circular
    makeCircular(head1);

    cout << "Example 1: Circular Linked List" << endl;
    printCircular(head1);

    if (isCircular(head1))
    {
        cout << "Linked List is Circular" << endl;
    }
    else
    {
        cout << "Linked List is NOT Circular" << endl;
    }

    // -------------------------------
    // Example 2: Non-Circular Linked List
    // -------------------------------

    Node *head2 = NULL;

    insertAtTail(head2, 50);
    insertAtTail(head2, 60);
    insertAtTail(head2, 70);
    insertAtTail(head2, 80);

    cout << "\nExample 2: Non-Circular Linked List" << endl;
    print(head2);

    if (isCircular(head2))
    {
        cout << "Linked List is Circular" << endl;
    }
    else
    {
        cout << "Linked List is NOT Circular" << endl;
    }

    return 0;
}