#include <iostream>
using namespace std;

void matrixAddition(int A[][3], int B[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void displayMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int rows = 3, cols = 3;

    int result[rows][cols];

    matrixAddition(A, B, result, rows, cols);

    cout << "Matrix A:" << endl;
    displayMatrix(A, rows, cols);

    cout << "Matrix B:" << endl;
    displayMatrix(B, rows, cols);

    cout << "Matrix Sum:" << endl;
    displayMatrix(result, rows, cols);

    return 0;
}
