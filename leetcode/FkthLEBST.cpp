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

int Solve(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = Solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    i++;

    if (i == k)
    {
        return root->data;
    }

    return Solve(root->right, i, k);
}

int KthSmallestBST(Node *root, int k)
{
    int i = 0;
    int ans = Solve(root, i, k);
    return ans;
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

    int k;
    cout << "Enter the Value\n";
    cin >> k;

    cout << endl;

    int KthLarge = KthSmallestBST(root, k);

    cout << k << "th Largest Element in BST is: " << KthLarge << endl;

    return 0;
}