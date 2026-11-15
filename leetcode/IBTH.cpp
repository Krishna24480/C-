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

int countNodes(node*root){

    if (root == NULL)
    {
        return 0;
    }
    

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(node * root,int index,int cnt){
    if (root == NULL)
    {
        return true;
    }

    if (index >= cnt)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, cnt);
        bool right = isCBT(root->right, 2 * index + 2, cnt);
        if(left && right){
            return true;
        }
        else
        {
            return false;
        }   
    }
}

bool isMaxOrder(node * root){
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if(left && right && (root->data>root->left->data && root->right->data))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool isHeap(node* root){
    int index = 0;
    int toatlCount = countNodes(root);

    if (isCBT(root,index,toatlCount)&& isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
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

    if (isHeap(root) == true)
    {
        cout << "Binary tree is a Heap" << endl;
    }
if (isHeap(root) == false)
{
    cout << "Binary tree is a Not Heap" << endl;
}

    return 0;
}