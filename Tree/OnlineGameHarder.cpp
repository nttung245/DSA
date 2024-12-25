#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;
        int size;
        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
            size = 1;
        }
    };
    Node *root = NULL;

    bool insert(Node *&root, int data)
    {
        if (root == 0)
        {
            root = new Node(data);
            return true;
        }
        bool kq;

        if (root->data == data)
            return false;
        if (data < root->data)
            kq = insert(root->left, data);
        else if (root->data < data)
            kq = insert(root->right, data);

        if (kq == true)
            root->size++;
        return kq;
    }

    int search(Node *root, int data)
    {
        int size1 = 0;
        while (root)
        {
            if (data == root->data)
            {
                size1 += 1 + (root->left ? root->left->size : 0);
                return size1;
            }
            else if (data < root->data)
            {
                root = root->left;
            }
            else
            {
                size1 += 1 + (root->left ? root->left->size : 0);
                root = root->right;
            }
        }
        return 0;
    }

    void DiTimNodeTheMang(Node *&X, Node *&Y)
    {
        if (Y->left)
        {
            DiTimNodeTheMang(X, Y->left);
            if (Y)
                Y->size--; // Thêm cập nhật size
        }
        else
        {
            X->data = Y->data;
            X = Y;
            Y = Y->right;
        }
    }

    bool XoaNode(Node *&t, int data)
    {
        if (!t)
            return false; // Nếu cây rỗng hoặc không tìm thấy node, trả về false

        bool deleted = false; // Biến theo dõi việc xóa có thành công không

        if (data < t->data)
        {
            deleted = XoaNode(t->left, data);
            if (deleted && t)
                t->size--; // Cập nhật size nếu xóa thành công
        }
        else if (data > t->data)
        {
            deleted = XoaNode(t->right, data);
            if (deleted && t)
                t->size--; // Cập nhật size nếu xóa thành công
        }
        else
        {
            // Đã tìm thấy node cần xóa
            Node *temp = t;
            if (!t->left)
            {
                t = t->right;
            }
            else if (!t->right)
            {
                t = t->left;
            }
            else
            {
                DiTimNodeTheMang(temp, t->right);
                if (t)
                    t->size--; // Cập nhật size sau khi thay thế node
            }
            delete temp;
            deleted = true; // Đánh dấu xóa thành công
        }

        return deleted; // Trả về kết quả xóa
    }

public:
    void _insert(int data)
    {
        insert(this->root, data);
    }

    int _search(int data)
    {
        return search(this->root, data);
    }

    void _XoaNode(int data)
    {
        XoaNode(this->root, data);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution myTree;

    int t;
    int data;

    while (cin >> t && t != 0)
    {
        std::cin >> data;
        if (t == 1)
        {
            myTree._insert(data);
        }
        else if (t == 2)
        {

            cout << myTree._search(data) << '\n';
        }
        else if (t == 3)
        {
            myTree._XoaNode(data);
        }
    }

    return 0;
}