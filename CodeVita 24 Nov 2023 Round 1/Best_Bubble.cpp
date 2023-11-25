#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int> A, int n, int B)
{
    int temp, count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (B == 1)
            {
                if (A[j] > A[j + 1])
                {
                    temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                    count++;
                }
            }
            else if (B == 0)
            {
                if (A[j] < A[j + 1])
                {
                    temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int AssCount = bubbleSort(arr, n, 1);
    int DssCount = bubbleSort(arr, n, 0);

    // cout << AssCount << endl;
    // cout << DssCount << endl;
    cout << min(AssCount, DssCount);

    return 0;
}
