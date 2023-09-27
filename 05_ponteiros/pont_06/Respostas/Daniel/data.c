#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data) {
    (*data).dia = dia;
    (*data).mes = mes;
    (*data).ano = ano;

    /*
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    */
}

void LeData( tData *data ) {
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);

    while (data->mes > 12) {
        data->mes--;
    }
    
    int diasNoMes = InformaQtdDiasNoMes(data);

    while (data->dia > diasNoMes) {
        data->dia--;
    }

}

void ImprimeData( tData *data ) {
    printf("'%02d/%02d/%04d'", (*data).dia, (*data).mes, (*data).ano);
    //printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ) {
    return (((*data).ano % 4 == 0 && 
            (*data).ano % 100 != 0) || 
            ((*data).ano % 400 == 0));

    /* return ((data->ano % 4 == 0 && 
                data->ano % 100 != 0) || 
                data->ano % 400 == 0);
    */
}

int InformaQtdDiasNoMes( tData *data ) {
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (data->mes == 2 && EhBissexto(data)) {
        return 29;
    }
    return diasNoMes[data->mes - 1];
}

void AvancaParaDiaSeguinte( tData *data ) {
    int qtdDiasMes = InformaQtdDiasNoMes(data);
    if (data->dia < qtdDiasMes) {
        data->dia++;
    } else {
        data->dia = 1;
        if (data->mes < 12) {
            data->mes++;
        } else {
            data->mes = 1;
            data->ano++;
        } 
    }
}

int EhIgual( tData *data1, tData *data2 ) {
    return (data1->dia == data2->dia && 
            data1->mes == data2->mes && 
            data1->ano == data2->ano);
}
