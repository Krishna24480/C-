// Merge 2 sorted link list

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

Node *merge(Node *head1, Node *head2)
{

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *head = NULL;
    Node *tail = NULL;

    if (head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {

        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return head;
}

int main()
{

    Node *head1 = NULL;

    insert(head1, 1);
    insert(head1, 3);
    insert(head1, 5);
    insert(head1, 7);

    Node *head2 = NULL;

    insert(head2, 2);
    insert(head2, 4);
    insert(head2, 6);
    insert(head2, 8);

    cout << "First List: ";
    print(head1);

    cout << "Second List: ";
    print(head2);

    Node *head = merge(head1, head2);

    cout << "Merged List: ";
    print(head);

    return 0;
}