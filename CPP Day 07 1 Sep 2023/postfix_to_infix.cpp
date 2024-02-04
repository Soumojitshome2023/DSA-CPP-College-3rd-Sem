#include <iostream>
#include <stack>

using namespace std;

// Check if a character is an operand
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Prefix to Infix conversion function
string prefixToInfix(string prefix)
{
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            // If operand, push it onto the stack
            s.push(string(1, prefix[i]));
        }
        else
        {
            // If operator, pop two operands, combine, and push back
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            s.push("(" + operand1 + prefix[i] + operand2 + ")");
        }
    }

    return s.top();
}

int main()
{
    string infix, prefix;
    cout << "Enter a PREFIX Expression: ";
    cin >> prefix;

    cout << "PREFIX EXPRESSION: " << prefix << endl;

    infix = prefixToInfix(prefix);

    cout << "INFIX EXPRESSION: " << infix << endl;

    return 0;
}
