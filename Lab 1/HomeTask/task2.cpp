#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for(int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for(int j = 0; j < cols; j++) data[i][j] = 0;
        }
    }

    ~Matrix() {
        for(int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for(int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for(int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if(this != &other) {
            for(int i = 0; i < rows; i++) delete[] data[i];
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            data = new int*[rows];
            for(int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for(int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    void set(int r, int c, int value) {
        if(r >= 0 && r < rows && c >= 0 && c < cols) data[r][c] = value;
        else cout << "Boundary error\n";
    }

    int get(int r, int c) const {
        if(r >= 0 && r < rows && c >= 0 && c < cols) return data[r][c];
        cout << "Boundary error\n";
        return -1;
    }

    void display() const {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        if(rows != other.rows || cols != other.cols) {
            cout << "Dimension mismatch\n";
            return Matrix(0,0);
        }
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
};

int main() {
    Matrix A(2,2);
    A.set(0,0,1); A.set(0,1,2);
    A.set(1,0,3); A.set(1,1,4);

    Matrix B(2,2);
    B.set(0,0,5); B.set(0,1,6);
    B.set(1,0,7); B.set(1,1,8);

    cout << "Matrix A:\n"; A.display();
    cout << "Matrix B:\n"; B.display();

    Matrix C = A + B;
    cout << "A + B:\n"; C.display();

    Matrix D = C;
    D.set(0,0,99);
    cout << "Matrix C after copy:\n"; C.display();
    cout << "Matrix D (modified copy):\n"; D.display();

    return 0;
}

