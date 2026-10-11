#include <iostream>
#include<queue>
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

Node* inserIntoBst(Node *root, int d) {

    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = inserIntoBst(root->right, d);
    }
    else{
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

int main()
{
    Node *root = NULL;

    cout << "Enter Data to Create BST: " << endl;

    takeInput(root);

    cout << "Print Binary Search Tree: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << "Printing InOrder Traversal: " << endl;
    InOrderTraversal(root);

    cout << endl;

    cout << "Printing PreOrder Traversal: " << endl;
    PreOrderTraversal(root);

    cout << endl;

    cout << "Printing PostOrder Traversal: " << endl;
    PostOrderTraversal(root);

    cout << endl;

    return 0;
}