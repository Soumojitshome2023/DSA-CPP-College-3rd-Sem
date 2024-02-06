#include <iostream>
using namespace std;

// ========================= Multiplication =========================
void matrixMultiplication(int A[][3], int B[][3], int result[][3], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ========================= Display =========================
void displayMatrix(int matrix[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ========================= Main =========================
int main()
{
    int A[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int rowsA = 3, colsA = 3, colsB = 3;

    int result[3][3];

    matrixMultiplication(A, B, result, rowsA, colsA, colsB);

    cout << "Matrix A:" << endl;
    displayMatrix(A, rowsA, colsA);

    cout << "Matrix B:" << endl;
    displayMatrix(B, colsA, colsB);

    cout << "Matrix Product:" << endl;
    displayMatrix(result, rowsA, colsB);

    return 0;
}

// ========================================================