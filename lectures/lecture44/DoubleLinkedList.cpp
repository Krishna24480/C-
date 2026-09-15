#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is Free: " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPostion(Node *&head, Node *&tail, int Postion, int d)
{
    if (Postion == 1)
    {
        insertAtHead(head,tail, d);
        return;
    }

    Node *temp = head;
    int Cnt = 1;

    while (Cnt < Postion - 1)
    {
        temp = temp->next;
        Cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head,tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void DeleteNode(int Postion, Node *&head, Node *&tail)
{
    if (Postion == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *Prev = NULL;

        int Cnt = 1;

        while (Cnt < Postion)
        {
            Prev = curr;
            curr = curr->next;
            Cnt++;
        }

        curr->prev = NULL;
        Prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void Print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    Print(head);

    int Length = getLength(head);

    cout << "Length Of DLL is: " << Length << endl;

    insertAtHead(head,tail, 4);
    insertAtHead(head,tail, 3);

    Print(head);

    Length = getLength(head);

    cout << "Length Of DLL is: " << Length << endl;

    insertAtTail(head,tail, 6);
    insertAtTail(head,tail, 7);

    Print(head);

    Length = getLength(head);

    cout << "Length Of DLL is: " << Length << endl;

    insertAtPostion(head, tail, 4, 66);
    Print(head);

    insertAtPostion(head, tail, 1, 100);
    Print(head);

    insertAtPostion(head, tail, 8, 888);
    Print(head);

    Length = getLength(head);

    cout << "Length Of DLL is: " << Length << endl;

    DeleteNode(1, head, tail);
    Print(head);

    Length = getLength(head);

    cout << "Length Of DLL is: " << Length << endl;

   DeleteNode(7, head, tail);
    Print(head);

   DeleteNode(3, head, tail);
   Print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}