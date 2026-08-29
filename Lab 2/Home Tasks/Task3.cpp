#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** m;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        m = new int*[rows];
        for(int i = 0; i < rows; i++)
            m[i] = new int[cols];
    }

    ~Matrix() {
        for(int i = 0; i < rows; i++)
            delete[] m[i];
        delete[] m;
    }

    void input() {
        cout << "Enter elements (" << rows << "x" << cols << "):\n";
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                cin >> m[i][j];
    }

    void display() const {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int get(int r, int c) const { return m[r][c]; }
    void set(int r, int c, int val) { m[r][c] = val; }

    friend Matrix add(const Matrix &a, const Matrix &b);
    friend Matrix multiply(const Matrix &a, const Matrix &b);
};

Matrix add(const Matrix &a, const Matrix &b) {
    if(a.rows != b.rows || a.cols != b.cols) {
        cout << "Error: Dimensions do not match for addition.\n";
        return Matrix(0,0);
    }
    Matrix c(a.rows, a.cols);
    for(int i = 0; i < a.rows; i++)
        for(int j = 0; j < a.cols; j++)
            c.set(i, j, a.get(i,j) + b.get(i,j));
    return c;
}

Matrix multiply(const Matrix &a, const Matrix &b) {
    if(a.cols != b.rows) {
        cout << "Error: Dimensions do not match for multiplication.\n";
        return Matrix(0,0);
    }
    Matrix c(a.rows, b.cols);
    for(int i = 0; i < a.rows; i++) {
        for(int j = 0; j < b.cols; j++) {
            int sum = 0;
            for(int k = 0; k < a.cols; k++)
                sum += a.get(i,k) * b.get(k,j);
            c.set(i,j,sum);
        }
    }
    return c;
}

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols for Matrix A: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);
    A.input();

    cout << "Enter rows and cols for Matrix B: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);
    B.input();

    int choice;
    do {
        cout << "\nMenu:\n1. Add\n2. Multiply\n3. Exit\nChoice: ";
        cin >> choice;

        if(choice == 1) {
            Matrix C = add(A,B);
            if(C.getRows() > 0) {
                cout << "Result of Addition:\n";
                C.display();
            }
        }
        else if(choice == 2) {
            Matrix C = multiply(A,B);
            if(C.getRows() > 0) {
                cout << "Result of Multiplication:\n";
                C.display();
            }
        }
    } while(choice != 3);

    cout << "Program terminated.\n";
    return 0;
}
