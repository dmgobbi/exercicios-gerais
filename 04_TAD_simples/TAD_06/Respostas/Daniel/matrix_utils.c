#include "matrix_utils.h"
#include <stdio.h>

tMatrix MatrixCreate(int rows, int cols) {
    tMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            matrix.data[i][j] = 0;
        }
    }

    return matrix;
}


tMatrix MatrixRead(tMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            scanf("%d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix) {
    int rows = matrix.rows;
    int cols = matrix.cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 0) {
                printf("|");
            }
            printf("%d", matrix.data[i][j]);
            if (j == cols - 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols;
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols;
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.cols == matrix2.rows;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    return result;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = MatrixCreate(matrix1.rows, matrix2.cols);
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            for (int k = 0; k < matrix2.rows; k++) {
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }
    return result;
}

tMatrix TransposeMatrix(tMatrix matrix) {
    tMatrix result = MatrixCreate(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++){
            result.data[j][i] = matrix.data[i][j];
        }
    }
    return result;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            matrix.data[i][j] *= scalar;
        }
    }
    return matrix;
}
