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

Node *LCAinBST(Node *root, int P, int Q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < P && root->data < Q)
    {
        return LCAinBST(root->right, P, Q);
    }

    if (root->data > P && root->data > Q)
    {
        return LCAinBST(root->left, P, Q);
    }

    return root;
}

Node *LCAinBST2(Node *root, int P, int Q)
{
    while (root != NULL)
    {
        if (root->data < P && root->data < Q)
        {
            root = root->right;
        }

        else if (root->data > P && root->data > Q)
        {
            root = root->left;
        }

        else
        {
            return root;
        }
    }
    
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

    cout << "Printing InOrder Traversal: " << endl;
    InOrderTraversal(root);

    cout << endl;

    int P;
    cout << "Enter First Value" << endl;
    cin >> P;

    int Q;
    cout << "Enter Second Value" << endl;
    cin >> Q;

    Node *Ans = LCAinBST(root, P, Q);

    cout << "Longest Common Ancesster of " << P << " and " << Q << " is: " << Ans->data << endl;

    Node *Ans2 = LCAinBST2(root, P, Q);

    cout << "Longest Common Ancesster of " << P << " and " << Q << " is: " << Ans2->data << endl;
    return 0;
}