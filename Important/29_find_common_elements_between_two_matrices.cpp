#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

// ========================= Input Matrix =========================
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter element at position [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// ========================= Find Common Element =========================
void findCommonElements(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    cout << "Common elements between the two matrices are:" << endl;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            for (int k = 0; k < rows; ++k)
            {
                for (int l = 0; l < cols; ++l)
                {
                    if (matrix1[i][j] == matrix2[k][l])
                    {
                        cout << matrix1[i][j] << " ";
                    }
                }
            }
        }
    }

    cout << endl;
}

// ========================= Main =========================
int main()
{
    int rows, cols;

    cout << "Enter the number of rows for the matrices: ";
    cin >> rows;

    cout << "Enter the number of columns for the matrices: ";
    cin >> cols;

    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];

    inputMatrix(matrix1, rows, cols);
    inputMatrix(matrix2, rows, cols);

    findCommonElements(matrix1, matrix2, rows, cols);

    return 0;
}

// =====================================================================