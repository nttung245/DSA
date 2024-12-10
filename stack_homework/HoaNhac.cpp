#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    long long count_pairs = 0;
    long long same = 0;
    stack<int> XepHang;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (XepHang.empty())
        {
            XepHang.push(x);
            continue;
        }
        else
        {
            if (x > XepHang.top())
            {
                // same = 0;
                while (!XepHang.empty())
                {
                    count_pairs++;
                    XepHang.pop();
                    if (!XepHang.empty() && x < XepHang.top())
                    {
                        count_pairs++;
                        break;
                    }
                    else if (!XepHang.empty() && x == XepHang.top() && XepHang.size() + 1 > 2)
                    {
                        same++;
                        count_pairs++;
                        count_pairs += same;
                        break;
                    }
                    else if (!XepHang.empty() && x == XepHang.top() && XepHang.size() + 1 <= 2)
                    {
                        count_pairs++;
                        break;
                    }
                    else
                    {
                        same = 0;
                    }
                }
                XepHang.push(x);
            }
            else if (x == XepHang.top() && XepHang.size() + 1 > 2)
            {
                same++;
                count_pairs++;
                count_pairs += same;
                XepHang.push(x);
            }
            else
            {
                XepHang.push(x);
                count_pairs++;
            }
        }
    }
    cout << count_pairs;
    return 0;
}