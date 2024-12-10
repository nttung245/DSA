#include <bits/stdc++.h>
using namespace std;

// Function to find precedence of operators.
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

// Function that returns value of expression after evaluation.
int evaluate(string tokens)
{
    stack<long> values;
    stack<char> ops;

    for (long i = 0; i < tokens.length(); i++)
    {
        // Skip whitespace
        if (tokens[i] == ' ')
            continue;

        // Handle opening parenthesis
        if (tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }
        // Handle numbers
        else if (isdigit(tokens[i]))
        {
            long val = 0;
            while (i < tokens.length() && isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--; // Correct offset
        }
        // Handle closing parenthesis
        else if (tokens[i] == ')')
        {
            while (!ops.empty() && (ops.top() != '('))
            {
                long val2 = values.top();
                values.pop();
                long val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Pop opening brace
            if (ops.top() == '(')
                ops.pop();
        }
        // Handle operators
        // Haven't fix yet
        else if (strchr("+-*/", tokens[i]))
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                long val2 = values.top();
                values.pop();
                long val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    // Apply remaining operations
    while (!ops.empty())
    {
        long val2 = values.top();
        values.pop();
        long val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main()
{
    string m;
    getline(cin, m);
    cout << evaluate(m) << endl;
    return 0;
}