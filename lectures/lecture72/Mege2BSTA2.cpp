#include <iostream>
#include <vector>
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


Node *mergeBST(Node *root1, Node *root2)
{

}

int main()
{
    Node *root1 = NULL;

    // Example Input:
    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1

    cout << "Enter Data to Create Root1 BST: " << endl;

    takeInput(root1);

    cout << "Print Binary Search Tree: " << endl;
    levelOrderTraversal(root1);

    cout << endl;

    Node *root2 = NULL;

    cout << "Enter Data to Create Root2 BST: " << endl;

    takeInput(root2);

    cout << "Print Binary Search Tree: " << endl;
    levelOrderTraversal(root2);

    cout << endl;

    Node *root3 = mergeBST(root1, root2);

    cout << "Merge Root1 And Root2 BST And Create Root3: " << endl;

    cout << endl;

    cout << "Print Merge Root3 Binary Search Tree: " << endl;
    levelOrderTraversal(root3);

    return 0;
}