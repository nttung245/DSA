
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long data;
    Node *left;
    Node *right;
    Node(long d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, long data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data < root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else if (data > root->data)
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
    bool search(Node *root, long data)
    {
        while (root)
        {
            if (data == root->data)
                return true;
            root = (data < root->data) ? root->left : root->right;
        }
        return false;
    }

    // void DiTimNodeTheMang(Node *&X, Node *&Y)
    // {
    //     if (Y->left != NULL)
    //     {
    //         DiTimNodeTheMang(X, Y->left);
    //     }
    //     else
    //     {
    //         X->data = Y->data;
    //         X = Y;
    //         Y = Y->right;
    //     }
    // }

    // void XoaNode(Node *&t, long data)
    // {
    //     if (t == NULL)
    //     {
    //         return;
    //     }
    //     else
    //     {
    //         if (data < t->data)
    //         {
    //             XoaNode(t->left, data);
    //         }
    //         else if (data > t->data)
    //         {
    //             XoaNode(t->right, data);
    //         }
    //         else
    //         {
    //             Node *X = t; // Node X la node the mang
    //             if (t->left == NULL)
    //             {
    //                 t = t->right;
    //             }
    //             else if (t->right == NULL)
    //             {
    //                 t = t->left;
    //             }
    //             else
    //             {
    //                 DiTimNodeTheMang(X, t->right); // Tim node con trai nhat cua nhanh ben phai
    //             }
    //             delete X;
    //         }
    //     }
    // }

}; // End of Solution
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution myTree;
    Node *root = NULL;

    int t;
    long data;

    while (cin >> t && t != 0)
    {
        std::cin >> data;
        if (t == 1)
        {
            root = myTree.insert(root, data);
        }
        else if (t == 2)
        {
            cout << myTree.search(root, data) << '\n';
        }
        // else if (t == 3)
        // {
        //     myTree.XoaNode(root, data);
        // }
    }

    return 0;
}