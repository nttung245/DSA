#include <iostream>
using namespace std;

int main()
{
    string m;
    cin >> m;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == '0')
            cout << "0";
        else
            cout << "1";
    }
    return 0;
}