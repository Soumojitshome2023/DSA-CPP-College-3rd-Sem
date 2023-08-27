#include<iostream>
#include<stdlib.h>

using namespace std;
#define max 10

int stack_s[max], stack_p[max], stack_q[max], top_s = -1, top_p = -1, top_q = -1;

//========================================Push========================================
int push(int val, int stack_name[], int *top_name){
	if(*top_name >= max-1)
		cout<<"Overflow";
	else	
		stack_s[++*top_name] = val;
}


//========================================Pop========================================
int pop(int stack_name[], int *top_name){
	if(*top_name <= -1)
		cout<<"Underflow";
	else{
		cout<<"Popped element"<<stack_name[*top_name];
		--*top_name;
	}
}


//========================================Display========================================
int display(int top_name, int stack_name[]){
		int i;
		if(top_name >=0){
			cout<<"Stack elements are : ";
			for(i = top_name; i >=0; i--)
				cout<<stack_name[i]<<" ";
		}
		else
			cout<<"Stack is empty";
}


//========================================ExChange========================================

int xchange(int top_name, int stack_name[]){
				cout<<"Enter number of element u want to ExChange: ";
				cin>>xnum;
				cout<<"Enter 1 for Stact P, 2 for Stack Q: ";
				cin>>stack_no;
				if(stack_no == 1){
					for(i = 0; i<xnum ;i++){
						push(stack_s[i], stack_p, &top_p);
					}
				}
				else if(stack_no == 2){
					for(i = 0; i<xnum ;i++){
						push(stack_s[i], stack_q, &top_q);
					}
				}
				display(top_p, stack_p);
}





//========================================Main========================================
int main(){

int ch, val, stack_name, xnum, stack_no,i ;

	do{
		cout<<endl;
		cout<<"1 Push"<<endl;
		cout<<"2 Pop"<<endl;
		cout<<"3 Display"<<endl;
		cout<<"4 Element ExChange"<<endl;
		cout<<"5 Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;

		switch(ch){
			case 1:
				cout<<"Enter the value to be inserted in 'Stack_S': ";
				cin>>val;
				push(val, stack_s, &top_s);
				break;
			case 2:
			
				pop(stack_s, &top_s);
				break;
			case 3: 
				display(top_s, stack_s);
				break;
			case 4:

				xchange();
				break;
				
			case 5:
				exit(0);
				break;
			default:
				cout<<"Wrong Choice";
		}

	}while(ch != 4);






	return 0;
}






//=====================================================================================








