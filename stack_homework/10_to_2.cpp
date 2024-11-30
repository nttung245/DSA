#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string m = "";
    while (n != 0)
    {
        m = to_string(n % 2) + m;
        n /= 2;
    }
    cout << m;
    return 0;
}