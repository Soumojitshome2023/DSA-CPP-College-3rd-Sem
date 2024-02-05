#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

// Check if a character is an operand
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to perform postfix to infix conversion
string postfixToInfix(string postfix)
{
    string stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            // If operand, push it onto the stack
            stack[++top] = string(1, postfix[i]);
        }
        else
        {
            // If operator, pop two operands, combine, and push back
            string operand2 = stack[top--];
            string operand1 = stack[top--];
            stack[++top] = "(" + operand1 + postfix[i] + operand2 + ")";
        }
    }

    return stack[top];
}

int main()
{
    string infix, postfix;
    cout << "Enter a POSTFIX Expression: ";
    cin >> postfix;

    cout << "POSTFIX EXPRESSION: " << postfix << endl;

    infix = postfixToInfix(postfix);

    cout << "INFIX EXPRESSION: " << infix << endl;

    return 0;
}
