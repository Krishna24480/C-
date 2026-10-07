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

// Create Parent Mapping
node *createParentMapping(
    node *root,
    int target,
    map<node *, node *> &nodeToParent)
{
    if (root == NULL)
    {
        return NULL;
    }

    node *res = NULL;

    queue<node *> q;

    q.push(root);

    // Root has no parent
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        // Check target
        if (front->data == target)
        {
            res = front;
        }

        // Left Child
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        // Right Child
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

// Burn Tree
int burnTree(
    node *root,
    map<node *, node *> &nodeToParent)
{
    if (root == NULL)
    {
        return 0;
    }

    // Keep track of visited nodes
    map<node *, bool> visited;

    queue<node *> q;

    q.push(root);

    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = false;

        int size = q.size();

        // Process one complete level
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            // Burn Left Child
            if (front->left &&
                !visited[front->left])
            {
                flag = true;

                q.push(front->left);

                visited[front->left] = true;
            }

            // Burn Right Child
            if (front->right &&
                !visited[front->right])
            {
                flag = true;

                q.push(front->right);

                visited[front->right] = true;
            }

            // Burn Parent
            if (nodeToParent[front] &&
                !visited[nodeToParent[front]])
            {
                flag = true;

                q.push(nodeToParent[front]);

                visited[nodeToParent[front]] = true;
            }
        }

        // One unit of time has passed
        // if at least one new node was burned
        if (flag)
        {
            ans++;
        }
    }

    return ans;
}

// Calculate Minimum Time to Burn Tree
int minTime(node *root, int target)
{
    map<node *, node *> nodeToParent;

    // Create parent mapping and find target node
    node *targetNode =
        createParentMapping(root, target, nodeToParent);

    // Target doesn't exist
    if (targetNode == NULL)
    {
        return 0;
    }

    // Burn tree starting from target
    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main()
{
    node *root = NULL;

    // Example:
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);

    cout << "\nLevel Order Traversal:\n";

    levelOrderTraversal(root);

    cout << endl;

    int target;

    cout << "Enter The Leaf Node You Want To Start Burn:\n";
    cin >> target;

    int timeToBurn = minTime(root, target);

    cout << "Total Time To Burn Tree Is: "<< timeToBurn << endl;

    return 0;
}