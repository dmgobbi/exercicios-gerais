#include "matrix_utils.h"
#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100

int main() {
    int rows1, cols1, rows2, cols2;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[MAX_ROW][MAX_COL];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[MAX_ROW][MAX_COL];
    matrix_read(rows2, cols2, matrix2);

    int result[MAX_ROW][MAX_COL];

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

        if (opcao == 1) {
            if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                matrix_add(rows1, cols1,  matrix1,  rows2, cols2, matrix2, result);
                matrix_print(rows1,  cols1, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        } else if (opcao == 2) {
            if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                matrix_sub(rows1, cols1,  matrix1,  rows2, cols2, matrix2, result);
                matrix_print(rows1,  cols1, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        } else if (opcao == 3) {
            if (possible_matrix_multiply(cols1, rows2)) {
                matrix_multiply(rows1, cols1,  matrix1,  rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        } else if (opcao == 4) {
            int scalar, numMatrix;
            scanf("%d %d", &scalar, &numMatrix);

            if (numMatrix == 1) {
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            } else if (numMatrix == 2) {
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            } 
        } else if (opcao == 5) {
            transpose_matrix(rows1, cols1, matrix1, result);
            matrix_print(cols1, rows1, result);

            transpose_matrix(rows2, cols2, matrix2, result);
            matrix_print(cols2, rows2, result);
        } else if (opcao == 6) {
            break;
        } 
    }
    
    return 0;
}
