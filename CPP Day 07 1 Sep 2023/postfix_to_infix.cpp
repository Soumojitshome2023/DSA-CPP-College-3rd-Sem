#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define SIZE 100

using namespace std;

char stack[SIZE];
int top = -1;

// Function to push an item onto the stack
void push(char item)
{
    if (top >= SIZE - 1)
        cout << "Stack overflow" << endl;
    else
    {
        top++;
        stack[top] = item;
    }
}

// Function to pop an item from the stack
char pop()
{
    char item;
    if (top < 0)
    {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

// Function to check if a character is an operand
bool isOperand(char c)
{
    return isalnum(c); // Using isalnum to check if it's an alphanumeric character
}

// Function to convert postfix to infix expression
void postfixToInfix(char postfix_exp[], char infix_exp[])
{
    int i, j;
    char operand1, operand2, operatorSymbol;

    for (i = 0; postfix_exp[i] != '\0'; i++)
    {
        if (isOperand(postfix_exp[i]))
        {
            push(postfix_exp[i]);
        }
        else if (postfix_exp[i] == '+' || postfix_exp[i] == '-' || postfix_exp[i] == '*' || postfix_exp[i] == '/')
        {
            operand2 = pop();
            operand1 = pop();
            operatorSymbol = postfix_exp[i];

            // Combine operands with the operator and surround with parentheses
            infix_exp[++top] = '(';
            infix_exp[++top] = operand1;
            infix_exp[++top] = operatorSymbol;
            infix_exp[++top] = operand2;
            infix_exp[++top] = ')';
        }
    }

    infix_exp[++top] = '\0';
}

// Main function
int main()
{
    char postfix[SIZE], infix[SIZE];

    cout << "Enter the postfix expression : ";
    cin >> postfix;

    postfixToInfix(postfix, infix);
    cout << "Infix expression : " << infix << endl;

    return 0;
}
