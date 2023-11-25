#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data {
    int dia;
    int mes;
    int ano;
};

int gFlagLeuData1 = 0;
int gFlagPrimeiraDataEhMaisRecente = 0;
tData* gData1;
tData* gData2;

tData* CriaData() {
    tData *data = (tData*) malloc(sizeof(tData));
    if (data == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    data->dia = -1;
    data->mes = -1;
    data->ano = -1;

    return data;
}

void InicializaDataParam( int dia, int mes, int ano, tData *data) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data ) {
    int dia, mes, ano;
    scanf(" %d/%d/%d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);

    while (data->mes > 12) data->mes--;
    
    int diasNoMes = NumeroDiasMes(data);

    while (data->dia > diasNoMes) data->dia--;

    // Using global variables to store the data
    if (!gFlagLeuData1) {
        gData1 = data;
        gFlagLeuData1 = 1;
    } else {
        gData2 = data;
        if (ComparaData(gData1, gData2) == 1) {
            gFlagPrimeiraDataEhMaisRecente = 1;
        }
    }

}

void LiberaData( tData *data ) {
    free(data);
}

int VerificaDataValida(tData* data) {
    int diasNoMes = NumeroDiasMes(data); 
    return (!gFlagPrimeiraDataEhMaisRecente && data->mes >= 1 && data->mes <= 12 && data->dia >= 1 && data->dia <= diasNoMes);
}

void ImprimeMesExtenso(tData* data) {
    const char mesExtenso[][10] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
                                   "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    if (data->mes >= 1 && data->mes <= 12) {
        printf("%s", mesExtenso[data->mes - 1]);
    } else {
        printf("Mes Invalido");
    }
}

void ImprimeDataExtenso(tData* data) {
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

int VerificaBissexto(tData* data) {
    return ((data->ano % 4 == 0 && 
            data->ano % 100 != 0) || 
            data->ano % 400 == 0);
}

int NumeroDiasMes(tData* data) {
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (data->mes == 2 && VerificaBissexto(data)) {
        return 29;
    }

    if (data->mes < 1 || data->mes > 12) return -1;

    return diasNoMes[data->mes - 1];
}

int EhIgual( tData *data1, tData *data2 ) {
    return (data1->dia == data2->dia && 
            data1->mes == data2->mes && 
            data1->ano == data2->ano);
}

int ComparaData(tData* data1, tData* data2) {
    if ((data1->ano > data2->ano) || 
        (data1->ano == data2->ano && data1->mes > data2->mes) || 
        (data1->ano == data2->ano && data1->mes == data2->mes && data1->dia > data2->dia)) {
        return 1;
    } else if (EhIgual(data1, data2)) {
        return 0;
    }
    return -1;
}

int CalculaDiasAteMes(tData* data) {
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int totalDeDias = 0;

    if (data->mes < 1 || data->mes > 12) return -1;

    for (int i = 0; i < data->mes; i++) {
        totalDeDias += diasNoMes[i];
        if (i == 2 && VerificaBissexto(data)) {
            totalDeDias++;
        }
    }

    return totalDeDias;
}

int CalculaDiferencaDias(tData* data1, tData* data2) {
    int dataComparada = ComparaData(data1, data2);

    if (!dataComparada) return 0;

    int diasAteMes1 = CalculaDiasAteMes(data1);
    int diasAteMes2 = CalculaDiasAteMes(data2);

    if (diasAteMes1 == -1 || diasAteMes2 == -1) return -1;

    int diferencaEntreDias = 0;

    tData* dataTemp = CriaData(); // Cria uma data temporaria para calcular a diferenca entre os anos

    for (int i = data1->ano; i < data2->ano; i++) {
        dataTemp->ano = i;
        diferencaEntreDias += VerificaBissexto(dataTemp) ? 366 : 365;
    }

    LiberaData(dataTemp);
    
    diferencaEntreDias -= (diasAteMes1 + data1->dia);
    diferencaEntreDias += (diasAteMes2 + data2->dia);
    
    return diferencaEntreDias;
}
