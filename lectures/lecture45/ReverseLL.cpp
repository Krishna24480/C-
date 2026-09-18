// Reverse a Link List using Loop and Recurison 
//  Find Middle of Link List

#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is Free: " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPostion(Node *&head, Node *&tail, int Postion, int d)
{
    if (Postion == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void DeleteNode(int Postion, Node *&head, Node *&tail)
{
    if (Postion == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
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

        Prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node *ReverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *Forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Forward;
    }
    return prev;
}

Node *ReverseLLUR(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = ReverseLLUR(head->next);

    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node* FindMiddle(Node* head){

    Node *Slow = head;
    Node *Fast = head;

    while (Fast!= NULL && Fast->next != NULL )
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
    }

    return Slow;
}

void Print(Node *&head)
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

    Node *node1 = new Node(5);

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    insertAtTail(tail, 10);

    cout << endl;

    cout << "Orignal List: " << endl;
    Print(head);

    // insertAtPostion(head, tail, 6, 66);
    // Print(head);

    // insertAtPostion(head, tail, 1, 100);
    // Print(head);

    // insertAtPostion(head, tail, 13, 1000000);
    // Print(head);

    // DeleteNode(1, head, tail);
    // Print(head);

    // DeleteNode(12, head, tail);
    // Print(head);

    // DeleteNode(6, head, tail);
    // Print(head);

    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // cout << "\n";

    // cout << "Print node1: " << endl;
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // cout << head->data << endl;
    // cout << tail->data << endl;

    // cout << "Reverse List: " << endl;
    // head = ReverseLL(head);
    // Print(head);

    cout << "Reverse List: " << endl;
    head = ReverseLLUR(head);
    Print(head);

    Node *Middle = FindMiddle(head);

    cout << "The Middle Node In a Link List is: " << Middle->data << endl;

    return 0;
}