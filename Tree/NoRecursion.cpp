
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    void preOrder(Node *root)
    {
        if (root == NULL)
            return; // Handle empty tree

        stack<Node *> my_stack; // Stack for nodes
        my_stack.push(root);    // Start with the root node

        while (!my_stack.empty())
        {
            // Process the current node
            Node *current = my_stack.top();
            my_stack.pop();
            cout << current->data << " ";

            // Push right child first (so it is processed after the left child)
            if (current->right != NULL)
            {
                my_stack.push(current->right);
            }

            // Push left child
            if (current->left != NULL)
            {
                my_stack.push(current->left);
            }
        }
    }

    void postOrder(Node *root)
    {
        if (root == NULL)
            return;

        stack<Node *> stack1, stack2;
        stack1.push(root);

        // Traverse the tree and store nodes in reverse post-order in stack2
        while (!stack1.empty())
        {
            Node *current = stack1.top();
            stack1.pop();
            stack2.push(current);

            // Push left and right children to stack1
            if (current->left)
            {
                stack1.push(current->left);
            }
            if (current->right)
            {
                stack1.push(current->right);
            }
        }

        // Print the nodes from stack2 (now in post-order)
        while (!stack2.empty())
        {
            cout << stack2.top()->data << " ";
            stack2.pop();
        }
    }
    void inOrder(Node *root)
    {
        stack<Node *> my_stack;
        Node *current = root;

        while (current != NULL || !my_stack.empty())
        {
            // Traverse the left subtree
            while (current != NULL)
            {
                my_stack.push(current);
                current = current->left;
            }

            // Process the node at the top of the stack
            current = my_stack.top();
            my_stack.pop();
            cout << current->data << " ";

            // Traverse the right subtree
            current = current->right;
        }
    }

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}