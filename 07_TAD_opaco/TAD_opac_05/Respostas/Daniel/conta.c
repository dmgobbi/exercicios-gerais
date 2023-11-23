#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "usuario.h"

struct Conta {
    int numero;
    float saldo;
    tUsuario *user;
};

tConta *CriaConta() {
    tConta* conta = (tConta*) calloc(1, sizeof(tConta));
    if (conta == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    } 
    conta->user = CriaUsuario();
    return conta;
}

void DestroiConta(tConta *conta) {
    free(conta->user);
    free(conta);
}

void LeConta(tConta *conta) {
    LeUsuario(conta->user);
    if (scanf("%d\n", &conta->numero) != 1)
        printf("Erro na leitura do numero da conta.\n");
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    return conta->numero == numero;
}

void SaqueConta(tConta *conta, float valor) {
    if (valor <= conta->saldo) 
        conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if (origem->saldo >= valor) {
        SaqueConta(origem, valor);
        DepositoConta(destino, valor);
    } 
}
