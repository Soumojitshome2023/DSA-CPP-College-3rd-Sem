#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Postfix Evaluation

#define size 10
using namespace std;
int stack[size], top = -1;

//================= Push Function =================
void push(int item)
{
	if (top >= size - 1)
	{
		cout << "Overflow";
		return;
	}
	else
		stack[++top] = item;
}

// ================= Pop Function =================
int pop()
{
	int item;
	if (top < 0)
	{
		cout << "Underflow";
		return 0;
	}
	else
	{
		item = stack[top];
		top--;
		return item;
	}
}

// ================= evalpost Function =================
void evalpost(char postfix[])
{
	int i, val, a, b;
	char ch;
	// push('(');
	// strcat(postfix, ')');
	for (i = 0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];
		if (isdigit(ch))
			push(ch - '0');
		else if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{
			a = pop();
			b = pop();

			switch (ch)
			{
			case '^':
				val = pow(b, a);
				break;
			case '*':
				val = b * a;
				break;
			case '/':
				val = b / a;
				break;
			case '+':
				val = b + a;
				break;
			case '-':
				val = b - a;
				break;
			}
			push(val);
		}
	}
	cout << "Result = " << val;
}

//================= isval Function =================
bool isval(char postfix[])
{
	int dig = 0, opp = 0;
	for (int i = 0; i <= strlen(postfix); i++)
	{
		if (isdigit(postfix[i]))
			dig++;
		else if (postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
			opp++;
	}

	if (dig == opp + 1)
		return true;
	else
		return false;
}
//================= Main Function =================
int main()
{
	char postfix[size];
	cout << "Enter Postfix exp : ";
	cin >> postfix;
	if (isval(postfix))
	{
		evalpost(postfix);
	}
	else
		cout << "Invalid";
	return 0;
}

//===================================================
