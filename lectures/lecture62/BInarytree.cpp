#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the Data: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter Data for Inserting in Left: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter Data for Inserting in Right: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Normal Level Order Traversal
void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

// Reverse Level Order Traversal
void ReverselevelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    stack<node *> s;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        s.push(temp);

        // IMPORTANT:
        // Push left first, then right.
        // Stack will automatically reverse the order.
        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    cout << "Reverse Level Order Traversal: ";

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        cout << temp->data << " ";
    }

    cout << endl;
}

// InOrder Traversal - LNR
void InOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

// PreOrder Traversal - NLR
void PreOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

// PostOrder Traversal - LRN
void PostOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

// Build Tree From Level Order
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter Data for Root" << endl;

    int data;
    cin >> data;

    if (data == -1)
    {
        root = NULL;
        return;
    }

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter Left Node for: " << temp->data << endl;

        int Leftdata;
        cin >> Leftdata;

        if (Leftdata != -1)
        {
            temp->left = new node(Leftdata);
            q.push(temp->left);
        }

        cout << "Enter Right Node for: " << temp->data << endl;

        int Rightdata;
        cin >> Rightdata;

        if (Rightdata != -1)
        {
            temp->right = new node(Rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    // Example Input:
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);

    cout << endl;

    cout << "Printing Tree: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    // cout << "Printing Reverse Level Order Traversal: " << endl;
    // ReverselevelOrderTraversal(root);

    cout << endl;

    cout << "Printing InOrder Traversal: " << endl;
    InOrderTraversal(root);

    cout << endl;

    cout << "Printing PreOrder Traversal: " << endl;
    PreOrderTraversal(root);

    // cout << endl;

    // cout << "Printing PostOrder Traversal: " << endl;
    // PostOrderTraversal(root);

    cout << endl;

    return 0;
}