#include <stdio.h>
#include <string.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos) {
    char nome[50]; 
    int dia;   
    int mes; 
    int ano;  

    if (*numEventos >= MAX_EVENTOS) {
        printf("Limite de eventos atingido!\n");
        return;
    }
    
    scanf(" %[^\n]\n", nome);
    scanf("%d %d %d", &dia, &mes, &ano);

    strcpy(eventos[*numEventos].nome, nome);
    eventos[*numEventos].dia = dia;
    eventos[*numEventos].mes = mes;
    eventos[*numEventos].ano = ano;
    *numEventos += 1;

    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos) {
    if (*numEventos <= 0) {
        printf("Nenhum evento cadastrado!\n");
        return;
    }
    
    printf("Eventos cadastrados:\n");
    for (int i = 0; i < *numEventos; i++) {
        printf("%d - %s - %02d/%02d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos) {
    int indice;
    int dia, mes, ano;

    scanf("%d", &indice);

    if (indice < 0 || indice >= *numEventos) {
        printf("Indice invalidos\n");
        return;
    }

    scanf("%d %d %d", &dia, &mes, &ano);

    for (int i = 0; i < *numEventos; i++) {
        if (i == indice) {
            eventos[i].dia = dia;
            eventos[i].mes = mes;
            eventos[i].ano = ano;   
            break; 
        }
    }

    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    Evento aux;
    int eventoSalvo = 0;

    if (*indiceA < 0 || 
        *indiceB < 0 || 
        *indiceA >= *numEventos || 
        *indiceB >= *numEventos) {
        printf("Indices invalidos!\n");
        return;
    }

    for (int i = 0; i < *numEventos; i++) {
        if (i == *indiceA) {
            aux = eventos[*indiceA]; 
            eventoSalvo = 1;
        }

        if (eventoSalvo) {
            eventos[*indiceA] = eventos[*indiceB];
            eventos[*indiceB] = aux;  
            break;
        }
    }

    printf("Eventos trocados com sucesso!\n");
}
