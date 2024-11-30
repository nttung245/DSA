#include <bits/stdc++.h>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }
};

struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void Nhap(DATHUC &B, double heso, int somu)
{
    DONTHUC *dt = new DONTHUC(heso, somu);
    Node *node = new Node(dt);

    if (!B.head)
    {
        B.head = node;
    }
    else
    {
        B.tail->next = node;
    }

    B.tail = node;
}

void Xuat(DATHUC &B)
{
    Node *dt = B.head;
    bool first = true; // Flag to check if it's the first term

    while (dt != nullptr)
    {
        // Skip nodes with coefficient 0
        if (dt->data->heso == 0)
        {
            dt = dt->next;
            continue;
        }

        // Handle signs
        if (dt->data->heso > 0 && !first)
        {
            cout << '+';
        }

        // Print the term based on the value of `heso` and `somu`
        if (dt->data->somu == 0)
        {
            // Constant term (x^0)
            cout << dt->data->heso;
        }
        else if (dt->data->somu == 1)
        {
            // Linear term (x^1)
            if (dt->data->heso == 1)
                cout << "x";
            else if (dt->data->heso == -1)
                cout << "-x";
            else
                cout << dt->data->heso << "x";
        }
        else
        {
            // Higher degree terms (x^somu)
            if (dt->data->heso == 1)
                cout << "x^" << dt->data->somu;
            else if (dt->data->heso == -1)
                cout << "-x^" << dt->data->somu;
            else
                cout << dt->data->heso << "x^" << dt->data->somu;
        }

        // Move to the next term
        dt = dt->next;
        first = false; // After the first term, we add '+' for positive terms
    }

    // If no terms were printed, output 0
    if (first)
        cout << "0";
}
// double pow(double x, int y)
// {
//     double sum = 1;
//     for (int i = 0; i < y; i++)
//     {
//         sum *= x;
//     }
//     return sum;
// }
#include <cmath>
double TinhDaThuc(DATHUC &B, double x)
{
    double sum = 0;
    Node *dt = B.head;
    while (dt != nullptr)
    {
        sum += dt->data->heso * (pow(x, dt->data->somu));
        dt = dt->next;
    }
    return sum;
}
int main()
{
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
