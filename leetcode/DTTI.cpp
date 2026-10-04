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

bool isIdentical(node *root1,node *root2){

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if (left && right && value)
    {
        return true;
    }
    else{
        return false;
    } 
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;

    cout << "First Binary Tree: \n";

    buildFromLevelOrder(root1); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout << "Second Binary Tree: \n";

    buildFromLevelOrder(root2);

    cout << "Print First Binary Tree: \n";

    levelOrderTraversal(root1);

    cout << "Print Second Binary Tree: \n";

    levelOrderTraversal(root2);

    if (isIdentical(root1,root2) == true)
    {
        cout << "Both BT are Identical\n";
    }
    else
    {
        cout << "Both BT are not Identical\n";
    }

    return 0;
}