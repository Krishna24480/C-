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

// PreOrder Traversal - NLR
void PreOrderTraversal(Node *root)
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
void PostOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

Node *minValue(Node *root)
{

    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{

    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *DeleteFromBST(Node *root, int val)
{

    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = DeleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = DeleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = DeleteFromBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    // Example Input:
    // 10 8 21 7 27 5 4 3 -1
    //50 20 70 10 30 90 110 -1

    cout << "Enter Data to Create BST: " << endl;

    takeInput(root);

    cout << "Print Binary Search Tree: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    // cout << "Printing InOrder Traversal: " << endl;
    // InOrderTraversal(root);

    // cout << endl;

    // cout << "Printing PreOrder Traversal: " << endl;
    // PreOrderTraversal(root);

    // cout << endl;

    // cout << "Printing PostOrder Traversal: " << endl;
    // PostOrderTraversal(root);

    cout << "Minimum Value in BST is: " << minValue(root)->data << endl;

    cout << "Maximum Value in BST is: " << maxValue(root)->data << endl;

    root = DeleteFromBST(root, 30);

    cout << "Print Binary Search Tree After Delete Node: " << endl;
    levelOrderTraversal(root);

    return 0;
}