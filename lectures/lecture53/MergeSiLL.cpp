//Merge Sort In Link List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert node at tail
void insertAtTail(Node *&head, int val)
{

    Node *newNode = new Node(val);

    // If list is empty
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

// Print linked list
void printList(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Find middle
Node *getMiddle(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge two sorted lists
Node *merge(Node *left, Node *right)
{

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (left != NULL && right != NULL)
    {

        if (left->data <= right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }

        temp = temp->next;
    }

    if (left != NULL)
        temp->next = left;
    else
        temp->next = right;

    return dummy->next;
}

// Merge Sort
Node *mergeSort(Node *head)
{

    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    // Find middle
    Node *middle = getMiddle(head);

    // Divide list
    Node *rightHead = middle->next;
    middle->next = NULL;

    // Sort left and right
    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHead);

    // Merge
    return merge(left, right);
}

int main()
{

    Node *head = NULL;

    // Insert using insertAtTail()
    insertAtTail(head, 40);
    insertAtTail(head, 10);
    insertAtTail(head, 30);
    insertAtTail(head, 20);
    insertAtTail(head, 50);

    cout << "Original Linked List: ";
    printList(head);

    // Merge Sort
    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}