#include <iostream>
#include <stdlib.h>

// ===================== Queue With Class =====================

using namespace std;
#define max 10

class Queue
{

	int queue[max], rear = -1, front = -1;

public:
	void enqueue()
	{
		int val;
		if (rear >= max - 1)
			cout << "Overflow" << endl;
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			cout << "Enter the value : ";
			cin >> val;
			rear++;
			queue[rear] = val;
		}
	}
	void dequeue()
	{
		if (front == -1 || front > rear)
			cout << "Underflow" << endl;
		else
		{
			cout << "Deleted element" << queue[front];
			front++;
		}
	}
	void display()
	{
		int i;
		if (front == -1 || front > rear)
			cout << "Queue is empty";
		else
		{
			cout << "Queue Element : ";
			for (i = front; i <= rear; i++)
			{
				cout << queue[i] << " ";
			}
		}
	}
};

int main()
{
	int ch;

	Queue q;

	do
	{
		cout << endl;
		cout << "1 EnQueue" << endl;
		cout << "2 DeQueue" << endl;
		cout << "3 Display" << endl;
		cout << "4 Exit" << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			// cout<<"Enter the value to be inserted : ";
			// cin>>val;
			q.enqueue();
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.display();
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
