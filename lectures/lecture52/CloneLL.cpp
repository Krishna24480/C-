// Clone a Link List with Random Pointers

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
    }
};

// Clone Linked List
Node *cloneLinkedList(Node *head)
{

    if (head == NULL)
        return NULL;

    // Step 1: Copy each node and insert after original node
    Node *curr = head;

    while (curr != NULL)
    {
        Node *copy = new Node(curr->data);

        copy->next = curr->next;
        curr->next = copy;

        curr = copy->next;
    }

    // Step 2: Copy random pointers
    curr = head;

    while (curr != NULL)
    {

        Node *copy = curr->next;

        if (curr->random != NULL)
            copy->random = curr->random->next;
        else
            copy->random = NULL;

        curr = copy->next;
    }

    // Step 3: Separate original and cloned list
    curr = head;

    Node *cloneHead = head->next;

    while (curr != NULL)
    {

        Node *copy = curr->next;

        curr->next = copy->next;

        if (copy->next != NULL)
            copy->next = copy->next->next;
        else
            copy->next = NULL;

        curr = curr->next;
    }

    return cloneHead;
}

// Print Linked List
void printList(Node *head)
{

    while (head != NULL)
    {

        cout << "Data: " << head->data;

        if (head->random != NULL)
            cout << ", Random: " << head->random->data;
        else
            cout << ", Random: NULL";

        cout << endl;

        head = head->next;
    }
}

int main()
{

    // Creating original linked list
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Connecting next pointers
    head->next = second;
    second->next = third;

    // Connecting random pointers
    head->random = third;   // 10 -> 30
    second->random = head;  // 20 -> 10
    third->random = second; // 30 -> 20

    cout << "Original List:" << endl;
    printList(head);

    // Clone the list
    Node *clone = cloneLinkedList(head);

    cout << "\nCloned List:" << endl;
    printList(clone);

    return 0;
}