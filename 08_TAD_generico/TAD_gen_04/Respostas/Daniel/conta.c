#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Conta {
    char *nome;
    int numero;
    float saldo;
};

tConta *CriaConta() {
    tConta *conta = calloc(1, sizeof(tConta));
    if (conta == NULL) {
        printf("Erro ao alocar memória para a conta bancária.\n");
        exit(EXIT_FAILURE);
    }
    return conta;
}

void DestroiConta(DataType conta) {
    tConta *c = (tConta *) conta;
    free(c->nome);
    free(c);
}

void LeConta(tConta *conta) {
    char nome[100];
    scanf("%d;%[^;];%f", &conta->numero, nome, &conta->saldo);
    conta->nome = strdup(nome);

    // Alternative to strdup
    // conta->nome = malloc(strlen(nome) + 1);  // Allocate memory for the name
    // if (conta->nome) {
    //     // strcpy(conta->nome, nome);
    //     memcpy(conta->nome, nome, strlen(nome) + 1); // Alternative to strcpy
    // } else {
    //     printf("Erro ao alocar memoria para o nome\n");
    // }
}

float GetSaldoConta(tConta *conta) {
    return conta->saldo;
}
