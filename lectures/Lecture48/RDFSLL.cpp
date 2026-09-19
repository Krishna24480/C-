// Remove Duplicate from Sorted Linked List

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

// Remove Duplicate
void removeDuplicate(Node *head)
{
    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *duplicate = temp->next;

            temp->next = duplicate->next;

            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }
}

// Print
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

int main()
{
    Node *head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 20);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 40);

    cout << "Before Removing Duplicate:" << endl;
    print(head);

    removeDuplicate(head);

    cout << "After Removing Duplicate:" << endl;
    print(head);

    return 0;
}