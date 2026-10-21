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

void InOrderTraversal(Node *root, vector<int> &inorderVal)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left, inorderVal);
    inorderVal.push_back(root->data);
    InOrderTraversal(root->right, inorderVal);
}

Node *InorderToBST(int s, int e, vector<int> &inorderVal)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    Node *root = new Node(inorderVal[mid]);

    root->left = InorderToBST(s, mid - 1, inorderVal);

    root->right = InorderToBST(mid + 1, e, inorderVal);

    return root;
}

Node *balanceBST(Node *root)
{
    vector<int> inorderVal;

    InOrderTraversal(root, inorderVal);

    return InorderToBST(0, inorderVal.size() - 1, inorderVal);
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

    Node *BalanceRoot = balanceBST(root);

    cout << "Print Balance Binary Search Tree: " << endl;
    levelOrderTraversal(BalanceRoot);

    return 0;
}