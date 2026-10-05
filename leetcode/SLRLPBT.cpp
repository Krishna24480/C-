#include <iostream>
#include <queue>
#include <limits.h>
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

void solve(node *root,int sum , int &maxSum , int len , int &maxlen){

    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }

        else if (len == maxlen)
        {
            maxSum = max(maxSum, sum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len, maxlen);
    solve(root->right, sum, maxSum, len, maxlen);
}

int sumOfLongRootToLeafPath(node* root){

    int length = 0;
    int maxlen = 0;
    int Sum = 0;

    int maxSum = INT_MIN;

    solve(root, Sum, maxSum, length, maxlen);

    return maxSum;
}

int main()
{
    node *root = NULL;

    buildFromLevelOrder(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTraversal(root);

    cout << endl;

    int Sum = sumOfLongRootToLeafPath(root);

    cout << "Sum of Long Root to Leaf Path is: " << Sum << endl;

    return 0;
}