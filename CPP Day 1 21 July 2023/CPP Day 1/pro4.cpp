#include<iostream>
using namespace std;

// Insert New Element in an Array 

int main(){

	int n;
	cout<<"Enter size of array : ";
	cin>>n;

	int arr[n+1],new_id, new_ele;

	for(int i=0;i<n;i++){
		cout<<"Enter element for index "<<i<< " : ";
		cin>>arr[i]; 	
	}

	cout<<"Your Array : ";

	for(int i=0;i<n;i++){
		cout<<arr[i]<< " , ";
		
	}
	
	cout<<"Enter new element's index : ";
	cin>>new_id; 
	cout<<"Enter new element : ";
	cin>>new_ele;

	for(int i = n+1; i>=new_id; i--){
		
		if(i==new_id){
			arr[i] = new_ele;
		}
		else
			arr[i]=arr[i-1];
	}

	cout<<"Your Array : ";

	for(int i=0;i<n+1;i++){
		cout<<arr[i]<< " , ";
		
	}

	return 0;
}
