#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

// ============================ Input ============================
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "matrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// ============================ Addition ============================
void matrixAddition(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// ============================ Display ============================
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols)
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

// ============================ Main ============================
int main()
{
    int rows, cols;

    cout << "Enter the number of rows for the matrices (max " << MAX_SIZE << "): ";
    cin >> rows;

    if (rows > MAX_SIZE)
    {
        cout << "Invalid input. Max size allowed is " << MAX_SIZE << "." << endl;
        return 1; // Exit with an error code
    }

    cout << "Enter the number of columns for the matrices (max " << MAX_SIZE << "): ";
    cin >> cols;

    if (cols > MAX_SIZE)
    {
        cout << "Invalid input. Max size allowed is " << MAX_SIZE << "." << endl;
        return 1; // Exit with an error code
    }

    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    cout << "\nEnter elements for the matrix 1:" << endl;
    inputMatrix(A, rows, cols);

    cout << "\nEnter elements for the matrix 2:" << endl;
    inputMatrix(B, rows, cols);

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Display Matrix A\n";
        cout << "2. Display Matrix B\n";
        cout << "3. Perform Matrix Addition\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Matrix A:" << endl;
            displayMatrix(A, rows, cols);
            break;

        case 2:
            cout << "Matrix B:" << endl;
            displayMatrix(B, rows, cols);
            break;

        case 3:
            cout << "Matrix addition performed." << endl;
            matrixAddition(A, B, result, rows, cols);
            cout << "Matrix Sum:" << endl;
            displayMatrix(result, rows, cols);
            break;

        case 0:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

// ========================================================