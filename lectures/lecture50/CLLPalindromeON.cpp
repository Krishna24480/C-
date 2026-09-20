//Check Link List Palindrome Or Not

#include <iostream>
#include <vector>
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

bool isPalindrome(Node *head)
{
    vector<int> arr;

    Node *temp = head;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        if (arr[i] != arr[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{

    //Example 1: Palindrome Linked List
    Node *head1 = NULL;

    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 2);
    insert(head1, 1);

    cout << "Linked List: ";
    print(head1);

    if (isPalindrome(head1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    cout << endl;

    // Example 2:Not Palindrome Linked List
    Node *head2 = NULL;

    insert(head2, 1);
    insert(head2, 2);
    insert(head2, 3);
    insert(head2, 2);
    insert(head2, 3);

    cout << "Linked List: ";
    print(head2);

    if (isPalindrome(head2))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}