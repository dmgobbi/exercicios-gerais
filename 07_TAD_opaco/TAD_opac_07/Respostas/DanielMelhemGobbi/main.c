#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    tData* data1 = CriaData();
    tData* data2 = CriaData();

    LeData(data1);
    LeData(data2);

    if (!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    } else { 
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);

        int compara = ComparaData(data1, data2);
        if (compara == 1) {
            printf("A primeira data eh mais recente\n");
        } else if (compara == -1) {
            printf("A primeira data eh mais antiga\n");
        } else {
            printf("As datas sao iguais\n");
        }

        int diferenca = CalculaDiferencaDias(data1, data2);
        printf("A diferenca em dias entre as datas eh: %02d dias\n", diferenca);
    }

    LiberaData(data1);
    LiberaData(data2);

    return 0;
}
