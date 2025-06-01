#include <iostream>
using namespace std;

class Matrix {
    int mat[10][10];
    int rows, cols;

public:
    void readMatrix() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];
    }

    void displayMatrix() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix add(Matrix m) {
        if (rows != m.rows || cols != m.cols)
            throw "Matrices are not compatible for addition!";
        Matrix temp;
        temp.rows = rows;
        temp.cols = cols;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
        return temp;
    }

    Matrix multiply(Matrix m) {
        if (cols != m.rows)
            throw "Matrices are not compatible for multiplication!";
        Matrix temp;
        temp.rows = rows;
        temp.cols = m.cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                temp.mat[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    temp.mat[i][j] += mat[i][k] * m.mat[k][j];
            }
        }
        return temp;
    }

    Matrix transpose() {
        Matrix temp;
        temp.rows = cols;
        temp.cols = rows;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.mat[j][i] = mat[i][j];
        return temp;
    }
};

int main() {
    Matrix A, B, C;
    int choice;

    cout << "Enter matrix A:\n";
    A.readMatrix();
    cout << "Enter matrix B:\n";
    B.readMatrix();

    do {
        cout << "\nMenu:\n";
        cout << "1. Add\n";
        cout << "2. Multiply\n";
        cout << "3. Transpose of A\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    C = A.add(B);
                    cout << "Result of Addition:\n";
                    C.displayMatrix();
                    break;
                case 2:
                    C = A.multiply(B);
                    cout << "Result of Multiplication:\n";
                    C.displayMatrix();
                    break;
                case 3:
                    C = A.transpose();
                    cout << "Transpose of Matrix A:\n";
                    C.displayMatrix();
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } catch (const char* msg) {
            cout << "Exception: " << msg << endl;
        }

    } while (choice != 4);

    return 0;
}
