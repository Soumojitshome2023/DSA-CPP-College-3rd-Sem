#include <iostream>
using namespace std;

// ============================ Array Input Output ============================

int main()
{

	int n;
	cout << "Enter size of array : ";
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter element for index " << i << " : ";
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Element of index " << i << " : " << arr[i] << "\n";
	}

	return 0;
}

// ========================================================