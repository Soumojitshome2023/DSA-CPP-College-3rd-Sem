
//===================== Stack | Push, Pop, Display =====================
#include <iostream>
#include <stdlib.h>

using namespace std;
#define max 10
int stack[max], top = -1;

// ============================= Push =============================
int push(int val)
{
	if (top >= max - 1)
	{
		cout << "Overflow";
	}
	else
		stack[++top] = val;
}

// ============================= Pop =============================
int pop()
{
	if (top <= -1)
		cout << "Underflow";
	else
	{
		cout << "Popped element" << stack[top];
		top--;
	}
}

// ============================= Display =============================
int display()
{
	int i;
	if (top >= 0)
	{
		cout << "Stack elements are : ";
		for (i = top; i >= 0; i--)
			cout << stack[i] << " ";
	}
	else
		cout << "Stack is empty";
}

// ============================= Main Function =============================
int main()
{
	int ch, val;

	do
	{
		cout << endl;
		cout << "1 Push" << endl;
		cout << "2 Pop" << endl;
		cout << "3 Display" << endl;
		cout << "4 Exit" << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter the value to be inserted : ";
			cin >> val;
			push(val);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Wrong Choice";
		}

	} while (ch != 4);

	return 0;
}
// ==================================================================================