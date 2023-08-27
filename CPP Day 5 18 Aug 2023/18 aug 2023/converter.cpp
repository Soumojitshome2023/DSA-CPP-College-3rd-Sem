#include<iostream>
#include"stack.cpp"
using namespace std;


int main(){

	int ch,dval, temp;
	cout<<"Enter Decimal Number : ";
	cin>>dval;
	while(dval != 0){

		temp = dval%2;
		push(temp);
		dval = dval/2;

	}
	cout<<"Binary Code :";
	display();
	









	return 0;
}

