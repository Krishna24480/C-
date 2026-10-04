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

int heightOBT(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOBT(root->left);
    int right = heightOBT(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

bool isBalance(node *root)
{

    if (root == NULL)
    {
        return true;
    }

    bool left = isBalance(root->left);
    bool right = isBalance(root->right);

    bool diff = abs(heightOBT(root->left) - heightOBT(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> isBalanceFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalanceFast(root->left);
    pair<bool, int> right = isBalanceFast(root->right);

    int leftans = left.first;
    int rightans = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftans && rightans && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isBalance2(node *root)
{
    return isBalanceFast(root).first;
}

pair<bool, int> isSumTreeFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool Cond = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if (left && right && Cond)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isSumTree(node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    node *root = NULL;

    buildFromLevelOrder(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTraversal(root);

    if (isSumTree(root) == true)
    {
        cout << "ISSum Tree\n";
    }
    else
    {
        cout << " Not ISSum Tree\n";
    }

    return 0;
}