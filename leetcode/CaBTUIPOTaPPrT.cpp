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
int findPosition(int inorder[], int element, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }

    return -1;
}

// Create Binary Tree
Node *solve(
    int inorder[],
    int postorder[],
    int &postorderIndex,
    int inorderStart,
    int inorderEnd)
{
    // Base Case
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Postorder gives the root from the end
    int element = postorder[postorderIndex];
    postorderIndex--;

    // Create root
    Node *root = new Node(element);

    // Find root position in Inorder
    int position = findPosition(
        inorder,
        element,
        inorderStart,
        inorderEnd);

    // IMPORTANT:
    // Since we are going backwards in Postorder,
    // we create RIGHT subtree first.

    // Create Right Subtree
    root->right = solve(
        inorder,
        postorder,
        postorderIndex,
        position + 1,
        inorderEnd);

    // Create Left Subtree
    root->left = solve(
        inorder,
        postorder,
        postorderIndex,
        inorderStart,
        position - 1);

    return root;
}

// Build Tree
Node *buildTree(int inorder[], int postorder[], int n)
{
    int postorderIndex = n - 1;

    Node *root = solve(
        inorder,
        postorder,
        postorderIndex,
        0,
        n - 1);

    return root;
}

// Preorder Traversal
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Node
    cout << root->data << " ";

    // Left
    preOrder(root->left);

    // Right
    preOrder(root->right);
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int *inorder = new int[n];
    int *postorder = new int[n];

    // Input Inorder
    cout << "Enter Inorder Traversal: ";

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    // Input Postorder
    cout << "Enter Postorder Traversal: ";

    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    // Construct Binary Tree
    Node *root = buildTree(inorder, postorder, n);

    // Print Preorder
    cout << "Preorder Traversal: ";

    preOrder(root);

    cout << endl;

    delete[] inorder;
    delete[] postorder;

    return 0;
}