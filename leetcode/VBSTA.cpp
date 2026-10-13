#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inserIntoBst(Node *root, int d)
{

    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = inserIntoBst(root->right, d);
    }
    else
    {
        root->left = inserIntoBst(root->left, d);
    }

    return root;
};

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = inserIntoBst(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
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

// InOrder Traversal - LNR
void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

bool isBst(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = isBst(root->left, min, root->data);
        bool right = isBst(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool isValiadeBST(Node *root)
{
    return isBst(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = NULL;

    // Example Input:
    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1

    cout << "Enter Data to Create BST: " << endl;

    takeInput(root);

    cout << "Print Binary Search Tree: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    if (isValiadeBST(root) == true)
    {
        cout << "it's a Valiade BST" << endl;
    }
    else
    {
        cout << "it's Not a Valiade BST" << endl;
    }

    return 0;
}