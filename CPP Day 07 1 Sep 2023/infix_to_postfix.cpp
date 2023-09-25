#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#define SIZE 100
using namespace std;

// Infix to Postfix

char stack[SIZE];
int top = -1;

// ============================= Push =============================
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

// ============================= Pop =============================
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

// ============================= Is Operator =============================
int isoperator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

// ============================= Precedence =============================
int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

// ============================= Infix to Postfix Function =============================
void inf_pos(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char x, item;
    push('(');
    strcat(infix_exp, ")");
    i = 0;
    j = 0;
    item = infix_exp[i];
    while (item != '\0')
    {
        if (item == '(')
            push(item);
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (isoperator(item) == 1)
        {
            x = pop();
            while (isoperator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            cout << "Invalid expression" << endl;
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    if (top > 0)
    {
        cout << "Invalid expression" << endl;
        exit(1);
    }
    postfix_exp[j] = '\0';
}
// ==================================================================================



// ============================= Input Valid or Not =============================
bool isValidInput(char infix_exp[])
{
    if (isoperator(infix_exp[0]) || isoperator(infix_exp[strlen(infix_exp) - 1]))
        return false;

    for (int i = 0; i < strlen(infix_exp) - 1; i++)
    {
        if (isoperator(infix_exp[i]) && isoperator(infix_exp[i + 1]))
        {
            return false;
        }
    }
    return true;
}


// ============================= Main Function =============================
int main()
{
    char infix[SIZE], postfix[SIZE];
    int i;
    cout << "Enter the infix expression : ";
    cin >> infix;

    if (!isValidInput(infix))
    {
        cout << "Wrong expression" << endl;
        exit(1);
    }

    inf_pos(infix, postfix);
    cout << "Postfix expression : " << postfix << endl;
    return 0;
}

// ===============================================================================