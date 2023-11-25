// Accepted

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void selection_sort(vector<int> &A, vector<int> &B, size_t n)
{
    size_t swaps = 0;

    for (size_t i = 0; i < n; ++i)
    {
        size_t min_index = i;

        for (size_t j = i + 1; j < A.size(); ++j)
        {
            if (A[j] < A[min_index])
            {
                min_index = j;
            }
        }

        // Swap elements in array A
        swap(A[i], A[min_index]);

        // Reflect the same swap in array B
        swap(B[i], B[min_index]);
        swaps += 1;

        if (swaps == n)
        {
            break;
        }
    }
}

int main()
{
    // Input arrays A and B
    vector<int> A, B;

    // Input array A
    string line;
    getline(cin, line);
    istringstream issA(line);
    int num;
    while (issA >> num)
    {
        A.push_back(num);
    }

    // Input array B
    getline(cin, line);
    istringstream issB(line);
    while (issB >> num)
    {
        B.push_back(num);
    }

    size_t n;
    cin >> n;

    selection_sort(A, B, n);

    // Output
    for (size_t i = 0; i < A.size(); ++i)
    {
        cout << B[i];
        if (i + 1 != A.size())
        {
            cout << " ";
        }
    }

    return 0;
}
