#include <iostream>
using namespace std;

/*==========================================
Best Time Complexity : O(n)
Average Time Complexity : O(n^2)
Worst Time Complexity : O(n^2)
Worst Space Complexity : O(1)
==========================================*/

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << ", ";
    }
    cout << endl;
}

// ====================== Bubble Sort ======================
void bubbleSort(int A[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// ====================== Main ======================
int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int n = 11;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array before sorting
    return 0;
}

// ===============================================================