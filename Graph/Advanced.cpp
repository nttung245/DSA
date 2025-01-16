#include <bits/stdc++.h>
using namespace std;
unordered_map<string, map<string, int>> adj;
unordered_map<string, bool> visited;
unordered_map<string, string> parent;

void dfs(string u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v.first])
        {
            parent[v.first] = u;
            dfs(v.first);
        }
    }
}

void Path(string s, string t)
{
    for (auto &v : visited)
    {
        v.second = false;
    }
    for (auto &p : parent)
    {
        p.second = "0";
    }
    dfs(s);
    if (!visited[t])
    {
        cout << "Khong co duong di! \n";
    }
    else
    {
        vector<string> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }

        path.push_back(s);
        reverse(path.begin(), path.end());

        for (auto i : path)
        {
            cout << i << ' ';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, n;
    cin >> v >> e >> n;
    unordered_map<string, int> vertices;
    for (int i = 0; i < v; i++)
    {
        string m;
        cin >> m;
        vertices[m] = i;
    }
    unordered_map<string, map<string, int>> graph;
    for (int i = 0; i < e; i++)
    {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        graph[s1][s2] = w;
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
            if (!graph[a].count(b))
            {
                cout << "FALSE" << '\n';
            }
            else
            {
                cout << graph[a][b] << '\n';
            }
            break;
        }
        case 2:
        {
            string a;
            cin >> a;
            if (graph[a].size() == 0)
            {
                cout << "NONE" << '\n';
            }
            else
            {
                vector<pair<int, int>> kq;
                for (const auto &p : graph[a])
                {
                    kq.push_back({vertices[p.first], p.second});
                }
                sort(kq.begin(), kq.end());
                for (const auto &p : kq)
                {
                    cout << p.second << ' ';
                }
                cout << '\n';
            }
            break;
        }
        }
    }
    return 0;
}