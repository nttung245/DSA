
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

class List
{
    struct Node
    {
        int val;
        Node *next;
    };

private:
    Node *head, *tail;

public:
    List()
    {
        this->head = this->tail = NULL;
    }
    Node *_head() { return this->head; }

    void add_tail(int x)
    {
        Node *p = new Node;
        p->val = x;
        p->next = NULL;

        if (this->head == NULL)
        {
            this->head = this->tail = p;
        }
        else
        {
            this->tail->next = p;
            this->tail = p;
        }
    }

    void for_each(std::function<void(int index, int &key)> func)
    {
        Node *current = this->head;
        int index = 0;
        while (current != NULL)
        {
            func(index, current->val);
            current = current->next;
            index++;
        }
    }
};

void secret1(int key, int &value);
void secret2(int key, int &value);
/// secret1 and secret2 function has been correctly and fully defined in the *real* template
/// students MUST NOT redefined these two  functions

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

    l.for_each(secret1);
    l.for_each(secret2);

    l.for_each([](int key, int &value)
               { cout << "phan tu thu " << key << " la " << value << endl; });

    return 0;
}
