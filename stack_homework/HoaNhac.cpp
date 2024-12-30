#include <bits/stdc++.h>
using namespace std;

struct data1
{
    long long height;
    int check_behind;
    long the_same;
} typedef data;

data1 info(long long h, int behind, long same)
{
    data1 tmp;
    tmp.height = h;
    tmp.check_behind = behind;
    tmp.the_same = same;
    return tmp;
}

int main()
{
    stack<data1> S;

    long n;
    cin >> n;
    long count = 0;
    for (long i = 1; i <= n; i++)
    {
        long long h;
        cin >> h;
        data1 TOP;
        if (!S.empty())
            TOP = S.top();
        if (S.empty())
        {
            S.push(info(h, 0, 0));
        }
        else if (!S.empty() && TOP.height > h)
        {
            S.push(info(h, 1, 0));
            count++;
        }
        else if (!S.empty() && TOP.height == h)
        {
            count++;
            count += TOP.the_same;
            if (TOP.check_behind == 1)
            {
                count++;
            }
            S.push(info(h, TOP.check_behind, TOP.the_same + 1));
        }
        else if (!S.empty() && TOP.height < h)
        {
            while (TOP.height < h)
            {
                count++;
                S.pop();
                if (S.empty())
                    break;
                TOP = S.top();
            }
            if (!S.empty())
                TOP = S.top();
            if (!S.empty() && TOP.height == h)
            {
                count++;
                count += TOP.the_same;
                if (TOP.check_behind == 1)
                {
                    count++;
                }
                S.push(info(h, TOP.check_behind, TOP.the_same + 1));
            }
            else if (!S.empty() && TOP.height > h)
            {
                count++;
                S.push(info(h, 1, 0));
            }
            else
                S.push(info(h, 0, 0));
        }
    }
    cout << count;
    return 0;
}