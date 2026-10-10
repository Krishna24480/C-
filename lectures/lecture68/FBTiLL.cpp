//Flatter a Binary Tree into a Linked List

#include <iostream>
#include <map>
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

// Build Binary Tree using Level Order
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter Data for Root: " << endl;

    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // Left Node
        cout << "Enter Left Node for: " << temp->data << endl;

        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        // Right Node
        cout << "Enter Right Node for: " << temp->data << endl;

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Level Order Traversal
void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

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

// Flatten Binary Tree to Linked List using Morris Traversal
void flatten(node *&root)
{
    node *current = root;

    while (current != NULL)
    {
        if (current->left != NULL)
        {
            node *temp = current->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }

            temp->right = current->right;

            current->right = current->left;
            current->left = NULL;
        }

        current = current->right;
    }
}

void PrintFlattenedList(node *root)
{
    node *current = root;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    node *root = NULL;

    // Example:
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);

    cout << endl;

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    cout << endl;

    flatten(root);
    cout << "Flattened Binary Tree to Linked List:" << endl;  
    PrintFlattenedList(root);

    cout << endl;

    return 0;
}