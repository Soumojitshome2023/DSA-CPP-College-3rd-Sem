#include <iostream>
using namespace std;

// ====================== Sparse Matrix Subtraction ======================
void subtractSparseMatrices(int rows, int cols, int mat1[][3], int mat2[][3], int result[][3])
{
    int size1, size2;

    // Input size of the first sparse matrix
    cout << "Enter the number of non-zero elements in the first matrix: ";
    cin >> size1;

    // Input elements of the first matrix
    cout << "Enter the row, column, and value for each non-zero element of the first matrix:\n";
    for (int i = 1; i <= size1; i++)
    {
        cout << "Row : ";
        cin >> mat1[i][0];
        cout << "Col : ";
        cin >> mat1[i][1];
        cout << "Val : ";
        cin >> mat1[i][2];
    }

    // Input size of the second sparse matrix
    cout << "Enter the number of non-zero elements in the second matrix: ";
    cin >> size2;

    // Input elements of the second matrix
    cout << "Enter the row, column, and value for each non-zero element of the second matrix:\n";
    for (int i = 1; i <= size2; i++)
    {
        cout << "Row : ";
        cin >> mat2[i][0];
        cout << "Col : ";
        cin >> mat2[i][1];
        cout << "Val : ";
        cin >> mat2[i][2];
    }

    // Initializing result matrix with zeros
    result[0][0] = rows;
    result[0][1] = cols;
    result[0][2] = 0;

    // Perform subtraction
    int i = 1, j = 1, k = 1;

    while (i <= size1 && j <= size2)
    {
        // Compare row and column indices
        if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1]))
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
        }
        else if (mat1[i][0] > mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1]))
        {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = -mat2[j][2]; // Negate the value for subtraction
            j++;
        }
        else
        {
            // Subtract values if indices are equal
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] - mat2[j][2];
            i++;
            j++;
        }
        k++;
    }

    // Copy remaining elements from the non-empty matrix
    while (i <= size1)
    {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }

    while (j <= size2)
    {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = -mat2[j][2]; // Negate the value for subtraction
        j++;
        k++;
    }

    // Update the size in the result matrix
    result[0][2] = k - 1;
}

// ============================= Display Sparse Matrix =============================
void displaySparseMatrix(int mat[][3])
{
    int rows = mat[0][0];
    int cols = mat[0][1];
    int size = mat[0][2];

    for (int i = 1; i <= size; i++)
    {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

// ============================= Main =============================
int main()
{
    int rows, cols;
    cout << "========= Enter the number of rows and columns for the matrices =========\n";
    cout << "Enter the number of rows : ";
    cin >> rows;
    cout << "Enter the number of columns : ";
    cin >> cols;

    int mat1[100][3], mat2[100][3], result[100][3];

    subtractSparseMatrices(rows, cols, mat1, mat2, result);

    cout << "Resultant sparse matrix after subtraction:\n";
    displaySparseMatrix(result);

    return 0;
}

// ==========================================================