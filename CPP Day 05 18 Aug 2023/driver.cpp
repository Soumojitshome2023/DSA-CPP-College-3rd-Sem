#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{

	int ch, val;

	do
	{
		cout << "\n1 Insert\n";
		cout << "2 Delete\n";
		cout << "3 Display\n";
		cout << "4 Exit\n";
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter value : ";
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
