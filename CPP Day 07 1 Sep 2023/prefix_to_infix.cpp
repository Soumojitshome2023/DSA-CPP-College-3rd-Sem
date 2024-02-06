#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define SIZE 100

using namespace std;

char stack[SIZE];
int top = -1;

// Function to push an item onto the stack
void push(char item) {
    if (top >= SIZE - 1)
        cout << "Stack overflow" << endl;
    else {
        top++;
        stack[top] = item;
    }
}

// Function to pop an item from the stack
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

// Function to check if a character is an operand
bool isOperand(char c) {
    return isalnum(c);  // Using isalnum to check if it's an alphanumeric character
}

// Function to convert prefix to infix expression
void prefixToInfix(char prefix_exp[], char infix_exp[]) {
    int length = strlen(prefix_exp);
    
    for (int i = length - 1; i >= 0; i--) {
        if (isOperand(prefix_exp[i])) {
            push(prefix_exp[i]);
        } else if (prefix_exp[i] == '+' || prefix_exp[i] == '-' || prefix_exp[i] == '*' || prefix_exp[i] == '/') {
            char operand1 = pop();
            char operand2 = pop();
            char operatorSymbol = prefix_exp[i];

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
int main() {
    char prefix[SIZE], infix[SIZE];

    cout << "Enter the prefix expression : ";
    cin >> prefix;

    prefixToInfix(prefix, infix);
    cout << "Infix expression : " << infix << endl;

    return 0;
}
