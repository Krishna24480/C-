// Largest Binary Search Tree in Binary Tree

#include <iostream>
#include <queue>
#include<limits.h>
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

class info
{

public:
    int maxi;
    int mini;
    bool isBST;
    int size;
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

info solve(node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }
    
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int LargestBST(node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main()
{
    node *root = NULL;

    // Example Input:
    // 8 3 12 2 8 17 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);

    cout << endl;

    cout << "Printing Tree: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    int Ans = LargestBST(root);

    cout << "Largest No. of BST in BT is: "<<Ans << endl;

    return 0;
}