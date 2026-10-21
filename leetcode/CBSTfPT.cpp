#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

// Create BST from Preorder Traversal
Node *buildBstFromPreorder(vector<int> &preorder, int &index,
                           int minVal, int maxVal)
{
    // Base case
    if (index >= preorder.size())
    {
        return NULL;
    }

    int element = preorder[index];

    // Check if element belongs to the current range
    if (element <= minVal || element >= maxVal)
    {
        return NULL;
    }

    // Create node
    Node *root = new Node(element);
    index++;

    // Build left subtree
    root->left = buildBstFromPreorder(
        preorder, index, minVal, element);

    // Build right subtree
    root->right = buildBstFromPreorder(
        preorder, index, element, maxVal);

    return root;
}

// Level Order Traversal
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

int main()
{
    vector<int> preorder;
    int n;

    // PreOrder Example

    // 17
    // 100 50 25 10 35 75 60 90 150 125 110 135 175 160 190 165 200

    // 10
    // 50 30 20 10 25 40 35 70 60 80

    // 5
    // 10 8 7 5 9 21 27

    cout
    << "Enter number of elements: ";
    cin >> n;

    cout << "Enter Preorder Traversal: " << endl;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        preorder.push_back(data);
    }

    int index = 0;

    Node *root = buildBstFromPreorder(
        preorder, index, INT_MIN, INT_MAX);

    cout << "Binary Search Tree (Level Order):" << endl;

    levelOrderTraversal(root);

    return 0;
}