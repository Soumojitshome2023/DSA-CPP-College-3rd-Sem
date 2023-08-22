#include<iostream>
using namespace std;

// Circular Queue Using Class

#define max 10

class Cq{
	int cq[max], front, rear;

	public:
	Cq(){
		front = -1; rear = -1;
	}
	void enqueue(){
		int val;
		if((front == 0 && rear == max-1)||(front == rear+1 )){
			cout<<"Queue Overflow";
			return;
		}
		else{
			cout<<"Enter the value : ";
			cin>>val;
			if(front == -1){
				front = 0;
				rear = 0;
			}
			else{
				if(rear == max -1)
					rear = 0;
				else
					rear++;
			}
			cq[rear] = val;
		}
	}

	void dequeue(){
		if(front == -1){
			cout<<"Queue Underflow";
			return;
		}
		
		else{
			cout<<"Deleted element : "<<cq[front];
			if(front == rear){
				front = -1; 
				rear = -1;
			}
			else{
				if(front == max-1)
					front = 0;
				else
					front++;
			}
		}
	}

	void display(){
		int i;
		if(front == -1)
			cout<<"Queue is Empty";
		else{
			cout<<"Element : ";
			i = front;
			if(front<= rear){
				while(i <= rear){
					cout<<cq[i]<<" ";
					i++;
				}

			}
			else{
				while(i <= max -1 )
					cout<<cq[i++]<<" ";
					i=0;
				while(i<=rear)
					cout<<cq[i++]<<" ";

			}
		}
	}
};

int main(){

	Cq cq;
	int ch;

	do{
		cout<<"\n1 Insert\n";
		cout<<"2 Delete\n";
		cout<<"3 Display\n";
		cout<<"4 Exit\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:	
				cq.enqueue();
				break;
			case 2:
				cq.dequeue();
				break;
			case 3:
				cq.display();
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

