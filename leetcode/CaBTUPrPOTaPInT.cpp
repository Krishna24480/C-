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

// Find position of element in Postorder
int findPosition(int postorder[], int element, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (postorder[i] == element)
        {
            return i;
        }
    }

    return -1;
}

// Construct Binary Tree using Preorder and Postorder
Node *solve(
    int preorder[],
    int postorder[],
    int &preorderIndex,
    int postorderStart,
    int postorderEnd,
    int n)
{
    // Base Case
    if (preorderIndex >= n || postorderStart > postorderEnd)
    {
        return NULL;
    }

    // Preorder gives the root
    int element = preorder[preorderIndex];
    preorderIndex++;

    // Create root
    Node *root = new Node(element);

    // If only one node is present
    if (postorderStart == postorderEnd)
    {
        return root;
    }

    // The next element in Preorder is the left child
    int nextElement = preorder[preorderIndex];

    // Find that element in Postorder
    int position = findPosition(
        postorder,
        nextElement,
        postorderStart,
        postorderEnd);

    // Create Left Subtree
    root->left = solve(
        preorder,
        postorder,
        preorderIndex,
        postorderStart,
        position,
        n);

    // Create Right Subtree
    root->right = solve(
        preorder,
        postorder,
        preorderIndex,
        position + 1,
        postorderEnd - 1,
        n);

    return root;
}

// Build Tree
Node *buildTree(int preorder[], int postorder[], int n)
{
    int preorderIndex = 0;

    return solve(
        preorder,
        postorder,
        preorderIndex,
        0,
        n - 1,
        n);
}

// Inorder Traversal
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Left
    inOrder(root->left);

    // Node
    cout << root->data << " ";

    // Right
    inOrder(root->right);
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int *preorder = new int[n];
    int *postorder = new int[n];

    // Input Preorder
    cout << "Enter Preorder Traversal: ";

    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    // Input Postorder
    cout << "Enter Postorder Traversal: ";

    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    // Construct Binary Tree
    Node *root = buildTree(preorder, postorder, n);

    // Print Inorder
    cout << "Inorder Traversal: ";

    inOrder(root);

    cout << endl;

    // Free memory
    delete[] preorder;
    delete[] postorder;

    return 0;
}