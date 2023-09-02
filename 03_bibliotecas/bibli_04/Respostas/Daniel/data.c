#include "data.h"
#include <stdio.h> 

int verificaDataValida(int dia, int mes, int ano) {
    int diasNoMes = numeroDiasMes(mes, ano);
    return (mes >= 1 && mes <= 12 && dia >= 1 && dia <= diasNoMes);
}

void imprimeData(int dia, int mes, int ano) {
    printf("%02d/%02d/%02d", dia, mes, ano);
}

void imprimeMesExtenso(int mes) {
    const char mesExtenso[][10] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
                                "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    if (mes >= 1 && mes <= 12) {
        printf("%s", mesExtenso[mes - 1]);
    } else {
        printf("Mes Invalido");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano) {
    return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) ? 1 : 0;
}

int numeroDiasMes(int mes, int ano) {
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && verificaBissexto(ano)) {
        return 29;
    }
    return diasNoMes[mes - 1];
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if ((ano1 > ano2) || (ano1 == ano2 && mes1 > mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 > dia2)) {
        return 1;
    } else if (ano1 == ano2 && mes1 == mes2 && dia1 == dia2) {
        return 0;
    }
    return -1;
}

int calculaDiasAteMes(int mes) {
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int totalDeDias = 0;

    if (mes < 1 || mes > 12) {
        return -1;
    }

    for (int i = 0; i < mes; i++) {
        totalDeDias += diasNoMes[i];
    }

    return totalDeDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int diferencaDias = 0;
    int dataComparada = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if (comparaData == 0) {
        return 0;
    } else if (dataComparada == 1) {
        int anoTemp = ano1;
        int mesTemp = mes1;
        int diaTemp = dia1;

        ano1 = ano2;
        mes1 = mes2;
        dia1 = dia2;

        ano2 = anoTemp; 
        mes2 = mesTemp;
        dia2 = diaTemp;
    }
    
    for (int i = ano1; i < ano2; i++) {
        diferencaDias += verificaBissexto(i) ? 366 : 365;
    }

    diferencaDias += (calculaDiasAteMes(mes2) + dia2);
    diferencaDias -= (calculaDiasAteMes(mes1) + dia1);

    if (verificaBissexto(ano2) && mes2 >= 2 ) {
        diferencaDias++;
    }

    return diferencaDias;
}

void imprimeProximaData(int dia, int mes, int ano) {
    int proxAno = ano;
    int proxMes = mes; 
    int proxDia = dia + 1;

    if (proxDia > numeroDiasMes(mes, ano)) {
        proxDia = 1;
        proxMes++;
    }

    if (proxMes > 12) {
        proxMes = 1;
        proxAno++;
    }

    printf("%02d/%02d/%04d", proxDia, proxMes, proxAno);
}
