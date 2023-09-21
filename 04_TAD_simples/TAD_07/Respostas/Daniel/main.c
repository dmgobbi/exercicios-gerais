#include "data.h"
#include <stdio.h>

int main() {
    int dia1, mes1, ano1, dia2, mes2, ano2;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    tData data1 = CriaData(dia1, mes1, ano1);
    tData data2 = CriaData(dia2, mes2, ano2);

    if (!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    int dataComparada = ComparaData(data2, data1); 

    if (dataComparada == -1) {
        printf("A primeira data eh mais antiga\n");
    } else if (!dataComparada) {
        printf("As datas sao iguais\n");
    } else {
        printf("A segunda data eh mais antiga\n");
    }

    int diferencaEntreDias = CalculaDiferencaDias(data1, data2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", diferencaEntreDias);

    return 0;
}
