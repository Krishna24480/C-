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

vector<int> mergeArrays(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }

    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

void InOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left, in);
    in.push_back(root->data);
    InOrder(root->right, in);
}

Node *InorderToBST(int s, int e, vector<int> &inorderVal)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    Node *root = new Node(inorderVal[mid]);

    root->left = InorderToBST(s, mid - 1, inorderVal);

    root->right = InorderToBST(mid + 1, e, inorderVal);

    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
    vector<int> bst1;
    vector<int> bst2;

    InOrder(root1, bst1);
    InOrder(root2, bst2);

    vector<int> mergerdArray = mergeArrays(bst1, bst2);

    int s = 0, e = mergerdArray.size() - 1;

    return InorderToBST(s, e, mergerdArray);
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

    Node *root3 = mergeBST(root1,root2);

    cout << "Merge Root1 And Root2 BST And Create Root3: " << endl;

    cout << endl;

    cout << "Print Merge Root3 Binary Search Tree: " << endl;
    levelOrderTraversal(root3);

    return 0;
}