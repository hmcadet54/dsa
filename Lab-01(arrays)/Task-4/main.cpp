#include <iostream>
#include "Task_4.cpp"

using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> rows1 >> cols1;

    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible due to incompatible dimensions." << endl;
        return 1;
    }

    
    int** matrix1 = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        matrix1[i] = new int[cols1];
        for (int j = 0; j < cols1; ++j) {
            cout << "Enter element [" << i << "][" << j << "] of matrix 1: ";
            cin >> matrix1[i][j];
        }
    }

    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; ++i) {
        matrix2[i] = new int[cols2];
        for (int j = 0; j < cols2; ++j) {
            cout << "Enter element [" << i << "][" << j << "] of matrix 2: ";
            cin >> matrix2[i][j];
        }
    }

    
    
    int** result = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        result[i] = new int[cols2];
    }

    
    matrix_multiply(matrix1, matrix2, result, rows1, cols1, cols2);
    cout << "Matrix multiplication result:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    
    deallocate_matrix(matrix1, rows1);
    deallocate_matrix(matrix2, rows2);
    deallocate_matrix(result, rows1);

    return 0;
}
