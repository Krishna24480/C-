//Reverse Link List in KGroup

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

    newNode->next = head;
    head = newNode;
}

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
        if (temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        temp = temp->next;
    }

    Node *newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at Head
void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;

    head = head->next;

    delete temp;
}

// Delete at Tail
void deleteAtTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // Only one node
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;
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

    if (position == 1)
    {
        deleteAtHead(head);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        if (temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
}

// Reverse in K Groups
Node *reverseKGroup(Node *head, int k)
{
    if (head == NULL || k <= 1)
    {
        return head;
    }

    // Check whether k nodes are available
    Node *temp = head;

    for (int i = 0; i < k; i++)
    {
        if (temp == NULL)
        {
            return head;
        }

        temp = temp->next;
    }

    // Reverse k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    for (int i = 0; i < k; i++)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    // Connect with next group
    head->next = reverseKGroup(curr, k);

    return prev;
}

// Print Linked List
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
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

    cout << "Linked List:" << endl;
    print(head);

    deleteAtHead(head);

    cout << "After Delete Head:" << endl;
    print(head);

    deleteAtTail(head);

    cout << "After Delete Tail:" << endl;
    print(head);

    deleteAtPosition(head, 2);

    cout << "After Delete Position 2:" << endl;
    print(head);

    head = reverseKGroup(head, 2);

    cout << "After Reverse in K Groups:" << endl;
    print(head);

    return 0;
}