#include <iostream>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    // Hàm chèn node vào đầu danh sách
    void insertNodeAtHead(int data)
    {
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
        if (this->head)
        {
            newNode->next = this->head;
        }
        else
        {
            this->tail = newNode; // Nếu danh sách trống, tail cũng phải trỏ đến node mới
        }
        this->head = newNode;
    }

    // Hàm chèn node vào cuối danh sách
    void insertNodeAtTail(int data)
    {
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
        if (this->tail)
        {
            this->tail->next = newNode;
        }
        else
        {
            this->head = newNode; // Nếu danh sách trống, head cũng phải trỏ đến node mới
        }
        this->tail = newNode;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }

    // Hàm đảo ngược danh sách liên kết
    void reverseLinkedList()
    {
        SinglyLinkedListNode *prev = nullptr;
        SinglyLinkedListNode *current = this->head;
        SinglyLinkedListNode *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        this->head = prev;
    }

    // Hàm in danh sách liên kết
    void printLinkedList()
    {
        SinglyLinkedListNode *p = this->head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Hàm giải phóng bộ nhớ
    void freeSinglyLinkedList()
    {
        SinglyLinkedListNode *node = this->head;
        while (node)
        {
            SinglyLinkedListNode *temp = node;
            node = node->next;
            delete temp;
        }
        this->head = this->tail = nullptr;
    }
};

// Hàm chèn node vào danh sách liên kết
void insert_node(SinglyLinkedList *llist, int data)
{
    if (!llist->head)
    {
        llist->head = new SinglyLinkedListNode(data);
        llist->tail = llist->head;
    }
    else
    {
        llist->tail->next = new SinglyLinkedListNode(data);
        llist->tail = llist->tail->next;
    }
}

// Hàm đảo ngược danh sách liên kết
void reverseLinkedList(SinglyLinkedList *llist)
{
    SinglyLinkedListNode *prev = nullptr;
    SinglyLinkedListNode *current = llist->head;
    SinglyLinkedListNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    llist->head = prev;
}

// Hàm in danh sách liên kết
void print_singly_linked_list(SinglyLinkedListNode *llist)
{
    SinglyLinkedListNode *p = llist;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// Hàm giải phóng bộ nhớ
void free_singly_linked_list(SinglyLinkedListNode *llist)
{
    SinglyLinkedListNode *node = llist;
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;
        delete temp;
    }
}
// Hàm trộn 2 danh sách liên kết
SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *head_list1, SinglyLinkedListNode *head_list2)
{

    if (!head_list1)
        return head_list2;
    if (!head_list2)
        return head_list1;

    SinglyLinkedListNode *new_list = nullptr;
    if (head_list1->data <= head_list2->data)
    {
        new_list = head_list1;
        head_list1 = head_list1->next;
    }
    else
    {
        new_list = head_list2;
        head_list2 = head_list2->next;
    }

    SinglyLinkedListNode *current = new_list;

    while (head_list1 != nullptr && head_list2 != nullptr)
    {
        if (head_list1->data <= head_list2->data)
        {
            current->next = head_list1;
            head_list1 = head_list1->next;
        }
        else
        {
            current->next = head_list2;
            head_list2 = head_list2->next;
        }
        current = current->next;
    }

    if (head_list1 != nullptr)
    {
        current->next = head_list1;
    }
    else
    {
        current->next = head_list2;
    }

    return new_list;
}

int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++)
    {
        int llist1_num, llist2_num;
        cin >> llist1_num >> llist2_num;

        SinglyLinkedList *llist1 = new SinglyLinkedList();

        for (int i = 0; i < llist1_num; i++)
        {
            int llist1_item;
            cin >> llist1_item;

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList *llist2 = new SinglyLinkedList();

        for (int i = 0; i < llist2_num; i++)
        {
            int llist2_item;
            cin >> llist2_item;

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode *llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3);

        free_singly_linked_list(llist3);
    }
}
