#include <iostream>
#include<vector>
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

void solve(node*root,int k,int &count,vector<int>path){

    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }   
    }
    path.pop_back();
}

int KSUM(node *root,int k)
{
    vector<int> path;
    int count = 0;

    solve(root, k, count, path);
    return count;
}

int main()
{
    node *root = NULL;

    buildFromLevelOrder(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTraversal(root);

    cout << endl;

    int k;
    cout << "Enter the Value of k: " << endl;
    cin >> k;

    int Sum = KSUM(root, k);

    cout << "Count Of " << k << " in Root is: " << Sum << endl;

    return 0;
}