#include <bits/stdc++.h>

using namespace std;

struct Login
{
    string username;
    string password;
};

struct Node
{
    Login data;
    Node *next;
};

struct LinkedList
{
    Node *head, *tail;
};

struct HashTable
{
    int M;
    int n;
    vector<LinkedList> table;
};

Node *CreateNode(const Login &x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(LinkedList &ll)
{
    ll.head = ll.tail = NULL;
}

void CreateHashTable(HashTable &ht, int m)
{
    ht.table.resize(m);
    for (int i = 0; i < m; i++)
        CreateList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

void Input(Login &l)
{
    cin >> l.username >> l.password;
}

int HashCode(const Login &x, int M)
{
    hash<string> stringHasher;
    size_t hashValue = stringHasher(x.username);
    return hashValue % M;
}

int HashCodeA(const string &x, int M)
{
    hash<string> stringHasher;
    size_t hashValue = stringHasher(x);
    return hashValue % M;
}

void AddTail(LinkedList &l, const Login &x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void InsertIntoTable(HashTable &ht, const Login &x)
{
    int hashIndex = HashCode(x, ht.M);
    AddTail(ht.table[hashIndex], x);
    ht.n++;
}

void Search(const HashTable &ht, const string &x)
{
    int index = HashCodeA(x, ht.M);
    Node *p = ht.table[index].head;
    bool found = false;
    while (p)
    {
        if (p->data.username == x)
        {
            cout << p->data.password << ' ';
            found = true;
        }
        p = p->next;
    }
    if (!found)
        cout << "Chua Dang Ky!";
}

void DeleteList(LinkedList &l)
{
    while (l.head)
    {
        Node *p = l.head;
        l.head = p->next;
        delete p;
    }
    l.head = l.tail = NULL;
}

void DeleteHashtable(HashTable &ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        DeleteList(ht.table[i]);
    }
    ht.table.clear();
    ht.M = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    HashTable hashTable;
    int n, q;
    string k;

    Login me;
    cin >> n >> q;
    CreateHashTable(hashTable, n);
    for (int i = 0; i < n; i++)
    {
        Input(me);
        InsertIntoTable(hashTable, me);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        Search(hashTable, k);
        cout << "\n";
    }
    DeleteHashtable(hashTable);
    return 0;
}