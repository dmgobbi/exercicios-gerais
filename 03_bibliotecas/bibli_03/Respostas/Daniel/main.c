#include "data.h"
#include <stdio.h>

int main() {
    int dia1, mes1, ano1, dia2, mes2, ano2;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if (!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    int comparadata = comparaData(dia1, mes1, ano1, dia2, mes2, ano2); 
    if (comparadata == -1) {
        printf("A primeira data eh mais antiga\n");
    } else if (comparadata == 0) {
        printf("As datas sao iguais\n");
    } else {
        printf("A segunda data eh mais antiga\n");
    }

    int diferencaEntredias = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", diferencaEntredias);

    return 0;
}
