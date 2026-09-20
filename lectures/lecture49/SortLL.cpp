// Sorted link list of 0s,1s,2s in C++

#include <iostream>
using namespace std;

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

void insert(Node *&head, int value)
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

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void sortByData(Node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }

    temp = head;

    while (count0--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    while (count1--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while (count2--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node *sortByPointers(Node *head)
{
    Node *zeroHead = NULL;
    Node *zeroTail = NULL;

    Node *oneHead = NULL;
    Node *oneTail = NULL;

    Node *twoHead = NULL;
    Node *twoTail = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = NULL;

        if (curr->data == 0)
        {
            if (zeroHead == NULL)
            {
                zeroHead = zeroTail = curr;
            }
            else
            {
                zeroTail->next = curr;
                zeroTail = curr;
            }
        }
        else if (curr->data == 1)
        {
            if (oneHead == NULL)
            {
                oneHead = oneTail = curr;
            }
            else
            {
                oneTail->next = curr;
                oneTail = curr;
            }
        }
        else
        {
            if (twoHead == NULL)
            {
                twoHead = twoTail = curr;
            }
            else
            {
                twoTail->next = curr;
                twoTail = curr;
            }
        }

        curr = nextNode;
    }

    Node *newHead = NULL;
    Node *newTail = NULL;

    if (zeroHead != NULL)
    {
        newHead = zeroHead;
        newTail = zeroTail;
    }

    if (oneHead != NULL)
    {
        if (newHead == NULL)
            newHead = oneHead;
        else
            newTail->next = oneHead;

        newTail = oneTail;
    }

    if (twoHead != NULL)
    {
        if (newHead == NULL)
            newHead = twoHead;
        else
            newTail->next = twoHead;

        newTail = twoTail;
    }

    return newHead;
}

int main()
{
    Node *head1 = NULL;

    insert(head1, 2);
    insert(head1, 1);
    insert(head1, 0);
    insert(head1, 2);
    insert(head1, 1);
    insert(head1, 0);

    cout << "Original List: ";
    print(head1);

    sortByData(head1);

    cout << "After Sorting By Data: ";
    print(head1);

    Node *head2 = NULL;

    insert(head2, 2);
    insert(head2, 1);
    insert(head2, 0);
    insert(head2, 2);
    insert(head2, 1);
    insert(head2, 0);

    cout << "\nOriginal List: ";
    print(head2);

    head2 = sortByPointers(head2);

    cout << "After Sorting By Pointers: ";
    print(head2);

    return 0;
}