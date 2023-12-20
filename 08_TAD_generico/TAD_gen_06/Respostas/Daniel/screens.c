#include "screens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void promptMatrixDetailsInput() {
    printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): ");
}

int promptMatrixOperationChoice() {
    while (1) {
        printf("Digite a operação desejada\n");
        printf("\t1 - Apenas imprimir a matriz\n");
        printf("\t2 - Converter para o tipo complexo e imprimir\n");
        printf("\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");

        int op;
        if (scanf("%d", &op) != 1) {
            printf("Error reading operation in function (promptMatrixOperationChoice)\n");
            return -1;
        } else {
            if (op >= 1 && op <= 3) return op;
            printf("\n");
        }   
    }

}

int promptEndOrContinue() {
    while (1) {
        printf("Digite a operação desejada\n");
        printf("\t1 - Entrar com uma nova matriz\n");
        printf("\t2 - Encerrar o Programa\n");

        int op;
        if (scanf("%d", &op) != 1) {
            printf("Error reading operation\n");
            return -1;
        }

        switch (op) {
            case 1:
                return 1;
            case 2:
                return 2;
            default:
                printf("\n");
        }
    }
}