#include "agencia.h"
#include "conta.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Agencia {
    int numero;
    char *nome;
    Vector *contas;
};

tAgencia *CriaAgencia() {
    tAgencia *agencia = (tAgencia *) calloc(1, sizeof(tAgencia));
    if (agencia == NULL) {
        printf("Erro na alocacao de memoria para a agencia.\n");
        exit(EXIT_FAILURE);
    }
    agencia->contas = VectorConstruct();
    return agencia;
}

void DestroiAgencia(DataType agencia) {
    tAgencia *agencia2 = (tAgencia *) agencia;
    free(agencia2->nome);
    VectorDestroy(agencia2->contas, DestroiConta);
    free(agencia2);
}

void LeAgencia(tAgencia *agencia) {
    char nomeAux[100];
    scanf("%d;%[^\n]%*c", &agencia->numero, nomeAux);
    agencia->nome = strdup(nomeAux);
}

void AdicionaConta(tAgencia *agencia, tConta *conta) {
    VectorPushBack(agencia->contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    return numAgencia == agencia2->numero;
}

float GetSaldoMedioAgencia(tAgencia *agencia) {
    float saldoTotal = 0;
    int numContas = VectorSize(agencia->contas);
    for (int i = 0; i < numContas; i++) {
        tConta *conta = VectorGet(agencia->contas, i);
        saldoTotal += GetSaldoConta(conta);
    }
    return saldoTotal / numContas;
}

void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->numero);
    printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("\tSaldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}
