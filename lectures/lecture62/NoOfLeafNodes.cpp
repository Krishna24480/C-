#include <iostream>
#include <queue>
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

void buildFromLevelOrder(node *&root)
{

    queue<node *> q;
    cout << "Enter Data for Root" << endl;
    int data;
    cin >> data;
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

void InOrderTraversal(node *root,int &count)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left,count);

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    InOrderTraversal(root->right,count);
}

int NoOfLeafNodes(node *root){

    int count = 0;
    InOrderTraversal(root, count);

    return count;
}


int main()
{
    node *root = NULL;

    buildFromLevelOrder(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    int NoOfLeaf = NoOfLeafNodes(root);

    cout << "No. Of Leaf Nodes In Binary Tree is: " << NoOfLeaf << endl;
    return 0;
}