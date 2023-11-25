#include <iostream>
#include <stdlib.h>
using namespace std;

// Stack

#define max 10

int stack[max], top = -1;
void push(int val)
{

	if (top >= max - 1)
	{
		cout << "Stack Overflow";
	}
	else
	{
		stack[++top] = val;
	}
}

void pop()
{
	if (top <= -1)
	{
		cout << "Stack Underflow";
	}

	else
	{
		cout << "Deleted element : " << stack[top];
		top--;
	}
}

void display()
{
	int i;
	if (top >= 0)
	{
		// cout<<"Element : ";
		for (int i = top; i >= 0; i--)
		{
			cout << stack[i] << " ";
		}
	}
	else
		cout << "Stack is Empty";
}
