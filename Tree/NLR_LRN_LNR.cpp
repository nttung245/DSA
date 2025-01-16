
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
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }
    void inOrder(Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
    void RNL(Node *root)
    {
        if (root != NULL)
        {
            RNL(root->right);
            cout << root->data << " ";
            RNL(root->left);
        }
    }

    void NRL(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            NRL(root->right);
            NRL(root->left);
        }
    }

    int DemNode2con(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL && root->right != NULL)
            {
                return 1 + DemNode2con(root->left) + DemNode2con(root->right);
            }
        }
        return 0;
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

    cout << myTree.DemNode2con(root);

    return 0;
}