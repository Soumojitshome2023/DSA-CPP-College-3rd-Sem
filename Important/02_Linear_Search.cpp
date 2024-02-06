#include <iostream>
using namespace std;

// ========================= Linear Search =========================
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i; // Element found
    }

    return -1; // Element not found
}

// ========================= Main =========================
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

// ========================================================