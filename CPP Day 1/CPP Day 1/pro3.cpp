#include<iostream>
using namespace std;

// Max Min

int main(){

	int n;
	cout<<"Enter size of array : ";
	cin>>n;

	int arr[n], max,min, max_ind=0, min_ind=0;

	for(int i=0;i<n;i++){
		cout<<"Enter element for index "<<i<< " : ";
		cin>>arr[i]; 	
	}

	max=arr[0];
	min=arr[0];

	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max = arr[i];
			max_ind = i;
		}

		else if(arr[i]<min){
			min = arr[i];
			min_ind = i;
		}
	}
	cout<<"max index is "<<max_ind<<" and val : "<<max<<" and min index is "<<min_ind<<" and val : "<<min;



	return 0;
}
