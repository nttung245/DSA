
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

class List
{
private:
    Node *head, *tail;

public:
    List()
    {
        this->head = this->tail = NULL;
    }
    Node *_head() { return this->head; }
    void add_tail(int value)
    {
        Node *newNode = new Node{value, NULL};
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    List(const List &other)
    {
        head = tail = NULL;
        if (other.head == NULL)
            return;
        Node *current = other.head;
        while (current)
        {
            add_tail(current->val);
            current = current->next;
        }
    }

    ~List()
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    List &operator=(const List &other)
    {
        if (this == &other)
            return *this;

        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }

        head = tail = NULL;
        if (other.head == NULL)
            return *this;

        current = other.head;
        while (current)
        {
            add_tail(current->val);
            current = current->next;
        }

        return *this;
    }
};

void X(List &a)
{
    if (a._head() == NULL)
    {
        cout << "NULL" << endl;
    }
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l;
    // Read list
    int x;
    do
    {
        cin >> x;
        l.add_tail(x);
    } while (x != 0);

    List l2 = l;

    Node *p = l._head(), *q = l2._head();
    while (p != NULL)
    {
        if (p == q || p->val != q->val)
            cout << "WRONG";
        cout << p->val << endl;
        p = p->next;
        q = q->next;
    }

    for (int i = 0; i < 2e3; i++)
    {
        X(l2);
        cout << i << endl;
    }

    return 0;
}
