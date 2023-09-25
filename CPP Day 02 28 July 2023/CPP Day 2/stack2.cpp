
// Stack | Class | Push, Pop, Display

#include<iostream>
#include<stdlib.h>

using namespace std;
#define max_size 100


class Stack{
	int top;
	int stack[max_size];
	
	public:
		Stack(){
			top = -1;
		}
	bool isEmpty(){			
		return (top==-1);
	}
	bool isFull(){
		return (top == max_size-1);
	}
	int push(int val){
		if(isFull())
			cout<<"Overflow";
		else{	
			stack[++top] = val;
			cout<<"Pushed element : "<<val;
		}
	}

	int pop(){
		if(isEmpty())
			cout<<"Underflow";

		else{
			cout<<"Popped element"<<stack[top];
			top--;
		}
	}

	int display(){
			if(isEmpty())
				cout<<"Stack is empty";
				
			else{
				cout<<"Stack elements are : ";
				for(int i=top; i >=0; i--)
					cout<<stack[i]<<" ";
			}
	}

};


int main(){
	int ch, val;

	Stack stack;

	do{
		cout<<endl;
		cout<<"1 Push"<<endl;
		cout<<"2 Pop"<<endl;
		cout<<"3 Display"<<endl;
		cout<<"4 Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the value to be inserted : ";
				cin>>val;
				stack.push(val);
				break;
			case 2: 
				stack.pop();
				break;
			case 3: 
				stack.display();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"Wrong Choice";
		}

	}while(ch != 4);

	return 0;
}
