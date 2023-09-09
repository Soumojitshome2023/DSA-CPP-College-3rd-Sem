#include <iostream>
#include <string.h>
// Sparse Matrix

using namespace std;

int main()
{
	int m, n, i, j, no_of_zero = 0;
	cout << "\nEnter number of row m =  ";
	cin >> m;
	cout << "\nEnter number of column n =  ";
	cin >> n;
	int matrix[m][n];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "\nEnter the element for row : " << i + 1 << " column : " << j + 1 << " : ";
			cin >> matrix[i][j];
			if (matrix[i][j] == 0)
				no_of_zero++;
		}
	}

	cout << "Your Matrix : " << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	if (no_of_zero > ((m * n) / 2))
	{
		cout << "sparse Matrix";

		cout << "\nRow     |     Column     |     Value";
		cout << "\n--------------------------------------";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] != 0)
				{
					cout << "\n"
						 << "   " << i + 1 << "\t\t" << j + 1 << "\t\t" << matrix[i][j];
				}
			}
		}
		cout << endl;
		/*
		cout<<"\nColumn : ";
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				if(matrix[i][j] != 0){
					cout<<j+1<<" ";
				}
			}
		}
		cout<<"\nValue  : ";
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				if(matrix[i][j] != 0){
					cout<<matrix[i][j]<<" ";
				}
			}
		}

	*/
	}
	else
		cout << "Not a sparse Matrix";

	return 0;
}
