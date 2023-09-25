#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9')) {
        return true;
    }
    else {
        return false;
    }
}

// ============================= Prefix to Infix Function =============================
string PrefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            string op(1, prefix[i]);
            //string op = prefix[i];
            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}

int main()
{
    string infix, prefix;
    cout << "Enter a PREFIX Expression :" << endl;
    cin >> prefix;
    cout << "PREFIX EXPRESSION: " << prefix << endl;
    infix = PrefixToInfix(prefix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;

    return 0;
}