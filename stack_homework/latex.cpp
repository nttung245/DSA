#include <bits/stdc++.h>

using namespace std;

int evaluate(string tokens)
{
    stack<char> s;
    for (long i = 0; i < tokens.length(); i++)
    {
        if (tokens[i] == '{' || tokens[i] == '(' || tokens[i] == '[')
        {
            s.push(tokens[i]);
        }
        else if (tokens[i] == '}' || tokens[i] == ')' || tokens[i] == ']')
        {
            if (s.empty())
            {
                return 0;
            }
            char top = s.top();
            if ((tokens[i] == '}' && top == '{') || (tokens[i] == ')' && top == '(') || (tokens[i] == ']' && top == '['))
            {
                s.pop();
            }
            else
            {
                return 0;
            }
        }
    }
    return s.empty() ? 1 : 0;
}
int main()
{
    string m;
    getline(cin, m);
    cout << evaluate(m);
    return 0;
}