#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    unsigned long key;
    Node *left;
    Node *right;
    int height;
    int size; // Size of subtree rooted at this node

    Node(unsigned long k) : key(k), left(nullptr), right(nullptr), height(1), size(1) {}
};

// Helper functions
int height(Node *N)
{
    return N ? N->height : 0;
}

int size(Node *N)
{
    return N ? N->size : 0;
}

void updateNodeStats(Node *N)
{
    if (N)
    {
        N->height = 1 + max(height(N->left), height(N->right));
        N->size = 1 + size(N->left) + size(N->right);
    }
}

Node *rightRotate(Node *y)
{
    if (!y || !y->left)
        return y;

    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateNodeStats(y);
    updateNodeStats(x);

    return x;
}

Node *leftRotate(Node *x)
{
    if (!x || !x->right)
        return x;

    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateNodeStats(x);
    updateNodeStats(y);

    return y;
}

int getBalance(Node *N)
{
    return N ? height(N->left) - height(N->right) : 0;
}

Node *insert(Node *node, unsigned long key)
{
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    updateNodeStats(node);

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

Node *deleteNode(Node *root, unsigned long key)
{
    if (!root)
        return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return nullptr;

    updateNodeStats(root);

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node *root, unsigned long key)
{
    while (root)
    {
        if (key == root->key)
            return true;
        root = (key < root->key) ? root->left : root->right;
    }
    return false;
}

int findIndex(Node *root, unsigned long key)
{
    if (!root)
        return -1;

    if (key < root->key)
        return findIndex(root->left, key);

    if (key > root->key)
    {
        int rightIndex = findIndex(root->right, key);
        if (rightIndex == -1)
            return -1;
        return size(root->left) + 1 + rightIndex;
    }

    return size(root->left);
}

// Clean up memory
void cleanup(Node *root)
{
    if (root)
    {
        cleanup(root->left);
        cleanup(root->right);
        delete root;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = nullptr;
    int operation;
    unsigned long value;

    while (cin >> operation && operation != 0)
    {
        if (!(cin >> value))
            break;

        switch (operation)
        {
        case 1:
            if (!search(root, value))
            {
                root = insert(root, value);
            }
            break;
        case 2:
            int index = findIndex(root, value);
            cout << (index != -1 ? to_string(index + 1) : "0") << '\n';
            break;
        }
    }

    cleanup(root); // Free memory before exiting
    return 0;
}