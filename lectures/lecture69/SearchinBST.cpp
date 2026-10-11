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

bool SearchinBST(Node* root, int x){

    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }
    
    if (root->data > x)
    {
        return SearchinBST(root->left, x);
    }
    else
    {
        return SearchinBST(root->right, x);
    }
    
}

bool SearchinBST2(Node *root, int x)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        if (temp->data>x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return false;
}

int main()
{
    Node *root = NULL;

    // Example Input:
    // 10 8 21 7 27 5 4 3 -1

    cout << "Enter Data to Create BST: " << endl;

    takeInput(root);

    cout << "Print Binary Search Tree: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    int x;
    cout << "Take the Input of x: " << endl;
    cin >> x;

    cout << endl;

    if (SearchinBST2(root,x) == true)
    {
        cout << "X is Present in BST" << endl;
    }
    else
    {
        cout << "X is not Present in BST" << endl;
    }
    
    return 0;
}