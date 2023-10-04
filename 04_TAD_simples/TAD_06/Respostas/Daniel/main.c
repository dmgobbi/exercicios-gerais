#include "matrix_utils.h"
#include <stdio.h>

#define MAX_MATRIX_SIZE 10

int main() {
    int rows1, cols1, rows2, cols2;
    int scalar, numMatrix;

    scanf("%d %d", &rows1, &cols1);
    tMatrix matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &rows2, &cols2);
    tMatrix matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);

    tMatrix result = MatrixCreate(MAX_MATRIX_SIZE, MAX_MATRIX_SIZE);

    int opcao;

    while (1) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (PossibleMatrixSum(matrix1, matrix2)) {
                    result = MatrixAdd(matrix1, matrix2);
                    MatrixPrint(result);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                }
                break;
            case 2:
                if (PossibleMatrixSub(matrix1, matrix2)) {
                    result = MatrixSub(matrix1, matrix2);
                    MatrixPrint(result);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                } 
                break;
            case 3: 
                if (PossibleMatrixMultiply(matrix1, matrix2)) {
                    result = MatrixMultiply(matrix1, matrix2);
                    MatrixPrint(result);
                } else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                }
                break;
            case 4:
                scanf("%d %d", &scalar, &numMatrix);

                switch (numMatrix) {
                    case 1:
                        matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                        MatrixPrint(matrix1);
                        break;
                    case 2: 
                        matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                        MatrixPrint(matrix2);
                        break;
                    default:
                        printf("Opcao invalida\n\n");
                        break;
                }
                break;
            case 5: 
                result = TransposeMatrix(matrix1);
                MatrixPrint(result);

                result = TransposeMatrix(matrix2);
                MatrixPrint(result);
                break;
            case 6:
                return 0;
            default:
                printf("Opcao invalida\n\n");
                break;
        }
    }  
    return 0;
}