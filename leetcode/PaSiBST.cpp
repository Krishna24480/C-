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

pair<int, int> PredSuCC(Node *root,int key)
{
    Node *temp = root;

    int pre = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }

    Node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    Node *rightTree = temp->right;
    while (rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pre, succ);
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

    int key;
    cout << "Enter the Value\n";
    cin >> key;
    cout << endl;

    pair<int, int> ans = PredSuCC(root, key);

    cout << "The Predecessor of " << key << " is: " << ans.first << endl;
    cout << "The Successor of " << key << " is: " << ans.second << endl;
    return 0;
}