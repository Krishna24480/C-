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

void levelOrderTraversal(node *root)
{
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

void  ReverselevelOrderTraversal (node* root){



}

void InOrderTraversal(node *root) //LNR
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(node *root) // NLR
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(node *root) //LRN 
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node* &root){

    queue<node*> q;
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

int main()
{
    node *root = NULL;

    buildFromLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 

    // root = buildTree(root);  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing Tree: " << endl;
    levelOrderTraversal(root);

    // L -> Left Part ma jao
    // N-> Print node
    // R ->  Right Part ma jao

    // cout << "Printing InOrder Tarversal: " << endl;
    // InOrderTraversal(root); //LNR //7 3 11 1 17 5

    // cout << endl;

    // cout << "Printing PreOrder Tarversal: " << endl;
    // PreOrderTraversal(root); // NLR //1 3 7 11 5 17

    // cout << endl;

    // cout << "Printing PostOrder Tarversal: " << endl;
    // PostOrderTraversal(root); // LRN  // 7 11 3 17 5 1

    return 0;
}