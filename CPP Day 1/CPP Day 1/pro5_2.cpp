#include<iostream>
using namespace std;

// Linear Search With Function


int linear_search(int arr[], int ele, int n);

int main(){

	int n;
	cout<<"Enter size of array : ";
	cin>>n;

	int arr[n], ele;

	for(int i=0;i<n;i++){
		cout<<"Enter element for index "<<i<< " : ";
		cin>>arr[i]; 	
	}

	cout<<"Your Array : ";

	for(int i=0;i<n;i++){
		cout<<arr[i]<< " , ";
		
	}
	
	cout<<"Enter the element to be searched : ";
	cin>>ele; 
	
	linear_search(arr,ele,n);

	return 0;
}



int linear_search(int arr[], int ele, int n){

	int ind = -1;
	for(int i = 0; i<n; i++){
		
		if(arr[i]==ele){
			ind =i;
		}
	}

	if(ind != -1){
		cout<<"Element found at index : "<<ind;
	}
	else
		cout<<"Not Found";

}





