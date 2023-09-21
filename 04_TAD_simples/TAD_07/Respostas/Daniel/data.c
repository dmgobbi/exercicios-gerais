#include "data.h"
#include <stdio.h> 

tData CriaData(int dia, int mes, int ano) {
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int VerificaDataValida(tData data) {
    int diasNoMes = NumeroDiasMes(data);
    return (data.mes >= 1 && data.mes <= 12 && data.dia >= 1 && data.dia <= diasNoMes);
}

void ImprimeMesExtenso(tData data) {
    const char mesExtenso[][10] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
                                   "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    if (data.mes >= 1 && data.mes <= 12) {
        printf("%s", mesExtenso[data.mes - 1]);
    } else {
        printf("Mes Invalido");
    }
}

void ImprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}

int VerificaBissexto(tData data) {
    return ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0));
}

int NumeroDiasMes(tData data) {
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (data.mes == 2 && VerificaBissexto(data)) {
        return 29;
    }

    if (data.mes < 1 || data.mes > 12) {
        return -1;
    }

    return diasNoMes[data.mes - 1];
}

int ComparaData(tData data1, tData data2) {
    if ((data1.ano > data2.ano) || (data1.ano == data2.ano && data1.mes > data2.mes) || 
        (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia > data2.dia)) {
        return -1;
    } else if (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia == data2.dia) {
        return 0;
    }
    return 1;
}

int CalculaDiasAteMes(tData data) {
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int totalDeDias = 0;

    if (data.mes < 1 || data.mes > 12) {
        return -1;
    }

    for (int i = 0; i < data.mes; i++) {
        totalDeDias += diasNoMes[i];
        if (i == 2 && VerificaBissexto(data)) {
            totalDeDias++;
        }
    }

    return totalDeDias;
}

int CalculaDiferencaDias(tData data1, tData data2) {
    int dataComparada = ComparaData(data1, data2);

    if (!dataComparada) {
        return 0;
    } else if (dataComparada == -1) {
        int anoTemp = data1.ano;
        int mesTemp = data1.mes;
        int diaTemp = data1.dia;

        data1.ano = data2.ano;
        data1.mes = data2.mes;
        data1.dia = data2.dia;

        data2.ano = anoTemp;
        data2.mes = mesTemp;
        data2.dia = diaTemp;
    }

    int diasAteMes1 = CalculaDiasAteMes(data1);
    int diasAteMes2 = CalculaDiasAteMes(data2);

    if (diasAteMes1 == -1 || diasAteMes2 == -1) {
        return -1;
    }

    int diferencaEntreDias = 0;
    for (int i = data1.ano; i < data2.ano; i++) {
        diferencaEntreDias += 365;  
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            diferencaEntreDias++;
        }
        //diferencaEntreDias += VerificaBissexto(data.ano) ? 366 : 365;
    }
    
    diferencaEntreDias -= (diasAteMes1 + data1.dia);
    diferencaEntreDias += (diasAteMes2 + data2.dia);
    
    return diferencaEntreDias;
}
