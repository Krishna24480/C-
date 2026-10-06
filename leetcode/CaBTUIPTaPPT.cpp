#include <iostream>
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

// Find the position of element in Inorder
int findPosition(int in[], int element, int inorderStart, int inorderEnd)
{
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }

    return -1;
}

// Recursive function to create the tree
Node *solve(
    int in[],
    int pre[],
    int &preOrderIndex,
    int inorderStart,
    int inorderEnd,
    int n)
{
    // Base Case
    if (preOrderIndex >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Preorder gives the root
    int element = pre[preOrderIndex];
    preOrderIndex++;

    // Create root node
    Node *root = new Node(element);

    // Find root position in Inorder
    int position = findPosition(
        in,
        element,
        inorderStart,
        inorderEnd);

    // Create Left Subtree
    root->left = solve(
        in,
        pre,
        preOrderIndex,
        inorderStart,
        position - 1,
        n);

    // Create Right Subtree
    root->right = solve(
        in,
        pre,
        preOrderIndex,
        position + 1,
        inorderEnd,
        n);

    return root;
}

// Build Binary Tree
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;

    Node *root = solve(
        in,
        pre,
        preOrderIndex,
        0,
        n - 1,
        n);

    return root;
}

// Print Postorder Traversal
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Left
    postOrder(root->left);

    // Right
    postOrder(root->right);

    // Node
    cout << root->data << " ";
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int *inorder = new int[n];
    int *preorder = new int[n];

    // Input Inorder
    cout << "Enter Inorder Traversal: ";

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    // Input Preorder
    cout << "Enter Preorder Traversal: ";

    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    // Construct Binary Tree
    Node *root = buildTree(inorder, preorder, n);

    // Print Postorder
    cout << "Postorder Traversal: ";

    postOrder(root);

    cout << endl;

    // Free memory
    delete[] inorder;
    delete[] preorder;

    return 0;
}