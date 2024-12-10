#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    // n la so sinh vien, m la so lan duoc goi
    long long n, m;
    cin >> n >> m;
    map<long long, int> XepHang;

    for (long i = 0; i < n; i++)
    {
        XepHang[i + 1] = 0;
    }

    stack<long long> stack1;
    stack<long long> stack2;

    for (int j = 0; j < m; j++)
    {
        long x;
        cin.ignore();
        cin >> x;
        stack1.push(x);
        stack2.push(x);
    }

    vector<long long> keys_to_erase;
    while (!stack2.empty())
    {
        keys_to_erase.push_back(stack2.top());
        stack2.pop();
    }

    for (auto key : keys_to_erase)
    {
        XepHang.erase(key);
    }

    stack<long long> stack3;
    for (auto it = XepHang.rbegin(); it != XepHang.rend(); ++it)
    {
        stack3.push(it->first);
    }

    unordered_map<long, int> check_before_add_stack2;

    while (!stack1.empty())
    {
        if (check_before_add_stack2.count(stack1.top()) == 0)
        {
            stack2.push(stack1.top());
            check_before_add_stack2[stack1.top()] = 0;
        }
        stack1.pop();
    }

    while (!stack2.empty())
    {
        stack3.push(stack2.top());
        stack2.pop();
    }

    while (!stack3.empty())
    {
        if (stack3.size() > 1)
            cout << stack3.top() << " ";
        else
            cout << stack3.top();
        stack3.pop();
    }

    return 0;
}