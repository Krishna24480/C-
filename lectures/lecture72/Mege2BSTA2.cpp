#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Insert data into BST
Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        return new Node(d);
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

// Take input until -1
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Level order traversal
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Convert BST into sorted Doubly Linked List
void convertIntoDoubleLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    // Process right subtree
    convertIntoDoubleLL(root->right, head);

    // Connect current node to DLL
    root->right = head;

    if (head != NULL)
    {
        head->left = root;
    }

    head = root;

    // Process left subtree
    convertIntoDoubleLL(root->left, head);
}

// Merge two sorted Doubly Linked Lists
Node *mergeDDLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        Node *temp;

        if (head1->data <= head2->data)
        {
            temp = head1;
            head1 = head1->right;
        }
        else
        {
            temp = head2;
            head2 = head2->right;
        }

        temp->left = tail;

        if (tail != NULL)
        {
            tail->right = temp;
        }
        else
        {
            head = temp;
        }

        tail = temp;
    }

    // Attach remaining nodes
    Node *remaining = (head1 != NULL) ? head1 : head2;

    while (remaining != NULL)
    {
        Node *next = remaining->right;

        remaining->left = tail;
        tail->right = remaining;

        tail = remaining;
        remaining = next;
    }

    tail->right = NULL;

    return head;
}

// Count nodes in DLL
int CountNodes(Node *head)
{
    int cnt = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

// Convert sorted DLL into balanced BST
Node *sortedLLtoBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // Build left subtree
    Node *leftSubtree = sortedLLtoBST(head, n / 2);

    // Current head becomes root
    Node *root = head;
    root->left = leftSubtree;

    // Move to next DLL node
    head = head->right;

    // Build right subtree
    root->right = sortedLLtoBST(head, n - n / 2 - 1);

    return root;
}

// Merge two BSTs into one balanced BST
Node *mergeBST(Node *root1, Node *root2)
{
    // Convert first BST into DLL
    Node *head1 = NULL;
    convertIntoDoubleLL(root1, head1);

    // Convert second BST into DLL
    Node *head2 = NULL;
    convertIntoDoubleLL(root2, head2);

    // Merge the two sorted DLLs
    Node *head = mergeDDLL(head1, head2);

    // Convert merged DLL into balanced BST
    int n = CountNodes(head);

    return sortedLLtoBST(head, n);
}

// Inorder traversal to verify sorted order
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    // Example Input:
    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1

    Node *root1 = NULL;

    cout << "Enter data to create Root1 BST (-1 to stop):" << endl;
    takeInput(root1);

    cout << "Root1 BST:" << endl;
    levelOrderTraversal(root1);

    Node *root2 = NULL;

    cout << "Enter data to create Root2 BST (-1 to stop):" << endl;
    takeInput(root2);

    cout << "Root2 BST:" << endl;
    levelOrderTraversal(root2);

    Node *root3 = mergeBST(root1, root2);

    cout << "Merged balanced BST:" << endl;
    levelOrderTraversal(root3);

    cout << "Inorder traversal of merged BST:" << endl;
    inorder(root3);
    cout << endl;

    return 0;
}