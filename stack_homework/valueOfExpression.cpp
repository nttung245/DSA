#include <bits/stdc++.h>
using namespace std;

// Function to find precedence of operators.
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == ':')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case ':':
        return a / b;
    }
    return 0;
}

// Function that returns value of expression after evaluation.
double evaluate(string tokens)
{
    stack<double> values;
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
            double val = 0;
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
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
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
        else if (strchr("+-*:", tokens[i]))
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
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
        double val2 = values.top();
        values.pop();
        double val1 = values.top();
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