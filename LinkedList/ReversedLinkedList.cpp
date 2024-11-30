
#include <iostream>
#include <limits>
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
};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
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
void printLinkedList(SinglyLinkedList *llist)
{
    SinglyLinkedListNode *p = llist->head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();
    int llist_count;

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }

    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
