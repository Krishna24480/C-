// Remove Duplicate from Unsorted Linked List

#include <iostream>
#include <unordered_set>
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
    if (head == NULL)
    {
        return;
    }

    unordered_set<int> seen;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (seen.find(temp->data) != seen.end())
        {
            Node *duplicate = temp;

            prev->next = temp->next;

            temp = temp->next;

            delete duplicate;
        }
        else
        {
            seen.insert(temp->data);

            prev = temp;
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
    insertAtTail(head, 30);
    insertAtTail(head, 20);
    insertAtTail(head, 10);
    insertAtTail(head, 40);
    insertAtTail(head, 30);
    insertAtTail(head, 20);

    cout << "Before Removing Duplicate:" << endl;
    print(head);

    removeDuplicate(head);

    cout << "After Removing Duplicate:" << endl;
    print(head);

    return 0;
}