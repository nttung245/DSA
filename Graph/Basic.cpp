#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, unordered_set<string>> graph;
    int e;
    cin >> e;
    int n;
    cin >> n;
    for (int i = 0; i < e; i++)
    {
        string a, b;
        cin >> a >> b;
        graph[a].insert(b);
        continue;
    }

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        switch (number)
        {
        case 1:
        {
            string a, b;
            cin >> a >> b;
            if (graph[a].find(b) != graph[a].end())
            {
                cout << "TRUE" << '\n';
            }
            else
            {
                cout << "FALSE" << '\n';
            }
            break;
        }

        case 2:
        {
            string a;
            cin >> a;
            cout << graph[a].size() << '\n';
            break;
        }
        }
    }
    return 0;
}