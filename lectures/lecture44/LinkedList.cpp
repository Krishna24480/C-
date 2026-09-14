#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL ;
        }
};

void insertAtHead(Node* &head,int d){

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail( Node *&tail, int d)
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

    while (Cnt<Postion-1)
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

void Print(Node* &head){
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

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

    Print(head);

    insertAtPostion(head,tail, 6, 66);
    Print(head);

    insertAtPostion(head, tail,1, 100);
    Print(head);

    insertAtPostion(head, tail, 13, 1000000);
    Print(head);

    // cout << node1->data << endl;
    // cout << node1->next << endl;
    return 0;
}