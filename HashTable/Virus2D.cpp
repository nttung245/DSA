#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m;
    vector<string> grid_1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid_1[i];
    }

    vector<string> grid_2(m, "");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid_2[i] += grid_1[j][i];
        }
    }

    for (auto i : grid_2)
    {
        cout << i << '\n';
    }
    return 0;
}