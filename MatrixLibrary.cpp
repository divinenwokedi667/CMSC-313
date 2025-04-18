#include <iostream>
#include <stdexcept>

class Matrix {
    public:
    Matrix(int r, int c) : rows(r), cols(c) {
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                this->at(i,j) = 0;
            }
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }

        delete arr;
    }
    int& at(int r, int c) {
        return arr[r][c];
    }
    const int& at(int r, int c) const {
        return arr[r][c];
    }
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) 
        throw std::invalid_argument("Matrices must match dimensions");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(i,j) = this->at(i,j) + other.at(i,j);
            }
        }

        return result;
    }

    Matrix operator*(int scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(i,j) = this->at(i,j) * scalar;
            }
        }

        return result;
    }
    Matrix transpose() const {
        Matrix result(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(j, i) = this->at(i, j);
            }
        }

        return result;
    }
    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) 
        throw std::invalid_argument("Matrices do not have compatible dimensions");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.at(i, j) += this->at(i, k) * other.at(k,j);
                }
                
            }
        }
        return result;
    }
    void print() {
        using namespace std;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << this->at(i,j) << " ";
            }
            cout << endl;
        }
    }


    private:
    int** arr;
    int rows;
    int cols;
};


int main() { //Test program
    using namespace std;
    //Testing equation: D = A + (B * 3) * C^T

    //Setting up A
    Matrix A(2,2);
    A.at(0,0) = 6; A.at(0,1) = 4; A.at(1,0) = 8; A.at(1,1) = 3;

    //Setting up B
    Matrix B(2, 3);
    B.at(0,0) = 1; B.at(0,1) = 2; B.at(0,2) = 3; B.at(1,0) = 4; B.at(1,1) = 5; B.at(1,2) = 6;

    //Setting up C
    Matrix C(2, 3);
    C.at(0,0) = 2; C.at(0,1) = 4; C.at(0,2) = 6; C.at(1,0) = 1; C.at(1,1) = 3; C.at(1,2) = 5;

    //Creating D using the equation
    Matrix D = A + (B * 3) * C.transpose();
    D.print();

    return 0;
}