#include <iostream>
using namespace std;

/*==========================================
Best Time Complexity : O(n^2)
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

// ====================== Selection Sort ======================
void selectionSort(int A[], int n)
{
    int indexOfMin, temp;

    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

// ====================== Main ======================
int main()
{
    /*==========================================
     Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
      00  01  02  03  04
     |03, 05, 02, 13, 12

     After first pass
      00  01  02  03  04
      02,|05, 03, 13, 12

     After second pass
     00  01  02  03  04
     02, 03,|05, 13, 12

     After third pass
     00  01  02  03  04
     02, 03, 05,|13, 12

     After fourth pass
     00  01  02  03  04
     02, 03, 05, 12,|13
    ==========================================*/

    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}

// ==================================================================