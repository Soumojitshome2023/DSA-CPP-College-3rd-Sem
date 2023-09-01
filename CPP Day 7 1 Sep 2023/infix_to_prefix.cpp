#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#define SIZE 100
using namespace std;

// infix to prefixs

char stack[SIZE];
int top = -1;

void push(char item) {
    if (top >= SIZE - 1)
        cout << "Stack overflow" << endl;
    else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    char item;
    if (top < 0) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int isoperator(char symbol) {
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix_exp[], char prefix_exp[]) {
    int i, j;
    char x, item;
    push(')');
    reverseString(infix_exp);
    strcat(infix_exp, "(");
    i = 0;
    j = 0;
    item = infix_exp[i];
    while (item != '\0') {
        if (item == ')')
            push(item);
        else if (isdigit(item) || isalpha(item)) {
            prefix_exp[j] = item;
            j++;
        } else if (isoperator(item) == 1) {
            x = pop();
            while (isoperator(x) == 1 && precedence(x) >= precedence(item)) {
                prefix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        } else if (item == '(') {
            x = pop();
            while (x != ')') {
                prefix_exp[j] = x;
                j++;
                x = pop();
            }
        } else {
            cout << "Invalid expression" << endl;
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    if (top > 0) {
        cout << "Invalid expression" << endl;
        exit(1);
    }
    prefix_exp[j] = '\0';
    reverseString(prefix_exp);
}

bool isValidInput(char infix_exp[]) {
    if (isoperator(infix_exp[0]) || isoperator(infix_exp[strlen(infix_exp) - 1]))
        return false;

    for (int i = 0; i < strlen(infix_exp) - 1; i++) {
        if (isoperator(infix_exp[i]) && isoperator(infix_exp[i + 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    char infix[SIZE], prefix[SIZE];
    int i;
    cout << "Enter the infix expression : ";
    cin >> infix;

    if (!isValidInput(infix)) {
        cout << "Wrong expression" << endl;
        exit(1);
    }

    infixToPrefix(infix, prefix);
    cout <<"Prefix expression : "<< prefix << endl;
    return 0;
}
