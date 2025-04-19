#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int** vals;
} Matrix;


Matrix createMatrix(int r, int c) {
    Matrix mat;
    mat.rows = r;
    mat.cols = c;
    mat.vals = (int**)malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        mat.vals[i] = (int*)malloc(sizeof(int) * c);
    }
    return mat;
}

void delMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->vals[i]);
    }
    free(mat->vals);
}

int get(Matrix* mat, int r, int c) {
    return mat->vals[r][c];
}

void set(Matrix* mat, int r, int c, int val) {
    mat->vals[r][c] = val;
}

Matrix add(Matrix* a, Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Dimensions are not compatible to add");
        exit(1);
    }
    Matrix result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.vals[i][j] = a->vals[i][j] + b->vals[i][j];
        }
    }

    return result;
}

Matrix transpose(Matrix* mat) {
    Matrix result = createMatrix(mat->cols, mat->rows);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.vals[i][j] = mat->vals[j][i];
        }
    }
    return result;
}

Matrix scalarMultiply(Matrix* mat, int scalar) {
    Matrix result = createMatrix(mat->rows, mat->cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.vals[i][j] = mat->vals[i][j] * scalar;
        }
    }
    return result;
}

Matrix multiply(Matrix* a, Matrix* b) {
    if (a->cols != b->rows) {
        printf("Dimensions are not compatible to multiply");
        exit(1);
    }

    Matrix result = createMatrix(a->rows, b->cols);
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.vals[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result.vals[i][j] += a->vals[i][k] * b->vals[k][j];
            }
        }
    }
    return result;
}

void print(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->vals[i][j]); //%d fixes casting error
        }
        printf("\n");
    }
}

int main() {
    //Creating Matrix A
    Matrix A = createMatrix(2, 2);
    set(&A, 0, 0, 6); set(&A, 0, 1, 4);
    set(&A, 1, 0, 8); set(&A, 1, 1, 3);

    //Creating Matrix B
    Matrix B = createMatrix(2, 3);
    set(&B, 0, 0, 1); set(&B, 0, 1, 2); set(&B, 0, 2, 3);
    set(&B, 1, 0, 4); set(&B, 1, 1, 5); set(&B, 1, 2, 6);

    //Creating Matrix C
    Matrix C = createMatrix(2, 3);
    set(&C, 0, 0, 2); set(&C, 0, 1, 4); set(&C, 0, 2, 6);
    set(&C, 1, 0, 1); set(&C, 1, 1, 3); set(&C, 1, 2, 5);

    //Creating Versions of Matrices Needed for Equation
    Matrix B3 = scalarMultiply(&B, 3);
    Matrix CT = transpose(&C);
    Matrix prod = multiply(&B3, &CT);
    Matrix D = add(&A, &prod); //these 4 statements are based on the order of operations

    printf("D = A + (3*B) x C^T:\n");
    print(&D);

    // Freeing the Memory
    delMatrix(&A);
    delMatrix(&B);
    delMatrix(&C);
    delMatrix(&B3);
    delMatrix(&CT);
    delMatrix(&prod);
    delMatrix(&D);
    
    return 0;
}