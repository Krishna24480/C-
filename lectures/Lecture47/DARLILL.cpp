// Detect and remove loop in link list

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

// Create a Loop
void createLoop(Node *head, int position)
{
    if (head == NULL)
    {
        return;
    }

    Node *loopNode = NULL;
    Node *temp = head;

    int count = 1;

    // Find the node at given position
    while (temp->next != NULL)
    {
        if (count == position)
        {
            loopNode = temp;
        }

        temp = temp->next;
        count++;
    }

    // Last node points to loopNode
    if (loopNode != NULL)
    {
        temp->next = loopNode;
    }
}

// Detect Loop
bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL)
    {
        return false;
    }

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int BigningOfLoop(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

    // Step 1: Detect loop
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }

    // No loop
    if (slow != fast)
    {
        return 0;
    }

    // Step 2: Find starting point of loop
    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}
    // Detect and Remove Loop
    void removeLoop(Node * head)
    {
        if (head == NULL)
        {
            return ;
        }

        Node *slow = head;
        Node *fast = head;

        // Step 1: Detect loop
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        // No loop
        if (slow != fast)
        {
            return;
        }

        // Step 2: Find starting point of loop
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Find last node of loop
        Node *temp = fast;

        while (temp->next != slow)
        {
            temp = temp->next;
        }

        // Remove loop
        temp->next = NULL;
    }

    // Print Linked List
    void print(Node * head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Main Function
    int main()
    {
        Node *head = NULL;

        insertAtTail(head, 10);
        insertAtTail(head, 20);
        insertAtTail(head, 30);
        insertAtTail(head, 40);
        insertAtTail(head, 50);

        // Create loop:
        // 50 -> 30
        createLoop(head, 3);

        // Check loop
        if (detectLoop(head))
        {
            cout << "Loop is present" << endl;
        }
        else
        {
            cout << "Loop is not present" << endl;
        }

      int Bigning = BigningOfLoop(head);

      cout << "Bigning Of Loop Is: " << Bigning << endl;

      // Remove loop
      removeLoop(head);

      // Check again
      if (detectLoop(head))
      {
          cout << "Loop is present" << endl;
      }
        else
        {
            cout << "Loop is removed" << endl;
        }

        // Print after removing loop
        cout << "Linked List:" << endl;
        print(head);

        return 0;
    }