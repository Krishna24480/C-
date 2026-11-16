#include <iostream>
#include <vector>

using namespace std;

// Structure of a Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert a node into BST
Node *insert(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Store BST values using Inorder Traversal
void inorder(Node *root, vector<int> &arr)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr);

    arr.push_back(root->data);

    inorder(root->right, arr);
}

// Replace values using Preorder Traversal
void preorder(Node *root, vector<int> &arr, int &index)
{

    if (root == NULL)
    {
        return;
    }

    root->data = arr[index++];

    preorder(root->left, arr, index);

    preorder(root->right, arr, index);
}

// Convert BST into Min Heap
void convertBSTtoMinHeap(Node *root)
{

    vector<int> arr;

    // Step 1: Store sorted values
    inorder(root, arr);

    // Step 2: Assign values in preorder
    int index = 0;

    preorder(root, arr, index);
}

// Print tree in preorder
void printPreorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    printPreorder(root->left);

    printPreorder(root->right);
}

int main()
{

    Node *root = NULL;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values: ";

    for (int i = 0; i < n; i++)
    {

        int val;
        cin >> val;

        root = insert(root, val);
    }

    // Convert BST to Min Heap
    convertBSTtoMinHeap(root);

    cout << "Min Heap (Preorder): ";

    printPreorder(root);

    cout << endl;

    return 0;
}