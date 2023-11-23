#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"

#define TAMANHO_INICIAL 5

struct Banco {
    tConta **contas;
    int qtdContas;
    int contasAlocadas;
};

tBanco *CriaBanco() {
    tBanco *banco = (tBanco*) malloc(sizeof(tBanco));
    if (banco == NULL) {
        printf("Erro na alocacao de memoria para o banco.\n");
        exit(1);
    }

    banco->contas = (tConta**) malloc(TAMANHO_INICIAL * sizeof(tConta*));
    if (banco->contas == NULL) {
        printf("Erro na alocacao de memoria para as contas.\n");
        free(banco);
        exit(1);
    }

    for (int i = 0; i < TAMANHO_INICIAL; i++) {
        banco->contas[i] = NULL;
    }

    banco->qtdContas = 0;
    banco->contasAlocadas = TAMANHO_INICIAL;
    return banco;
}

void DestroiBanco(tBanco *banco) {
    if (banco) {
        for (int i = 0; i < banco->qtdContas; i++) {
            DestroiConta(banco->contas[i]);
        }
        free(banco->contas);
        free(banco);
    }
}

void AbreContaBanco(tBanco *banco) {
    if (banco->qtdContas == banco->contasAlocadas) {
        banco->contas = (tConta**) realloc(banco->contas, (banco->contasAlocadas + TAMANHO_INICIAL) * sizeof(tConta*));
        if (!banco->contas) {
            printf("Erro na realocacao de memoria para as contas.\n");
            exit(EXIT_FAILURE);
        }
        banco->contasAlocadas += TAMANHO_INICIAL;
    }

    banco->contas[banco->qtdContas] = CriaConta();
    LeConta(banco->contas[banco->qtdContas]);
    banco->qtdContas++;
}

void SaqueContaBanco(tBanco *banco) {
    int numero;
    float valor;
    scanf("%d %f", &numero, &valor);

    for (int i = 0; i < banco->qtdContas; i++) {
        if (VerificaConta(banco->contas[i], numero)) {
            SaqueConta(banco->contas[i], valor);
            return;
        }
    }
    printf("Conta nao encontrada.\n");
}

void DepositoContaBanco(tBanco *banco) {
    int numero;
    float valor;
    scanf("%d %f", &numero, &valor);

    for (int i = 0; i < banco->qtdContas; i++) {
        if (VerificaConta(banco->contas[i], numero)) {
            DepositoConta(banco->contas[i], valor);
            return;
        }
    }
    printf("Conta nao encontrada.\n");
}

void TransferenciaContaBanco(tBanco *banco) {
    int numeroOrigem, numeroDestino;
    float valor;

    scanf("%d %d %f", &numeroOrigem, &numeroDestino, &valor);

    tConta *contaOrigem = NULL;
    tConta *contaDestino = NULL;

    for (int i = 0; i < banco->qtdContas; i++) {
        if (VerificaConta(banco->contas[i], numeroOrigem)) {
            contaOrigem = banco->contas[i];
        }
        if (VerificaConta(banco->contas[i], numeroDestino)) {
            contaDestino = banco->contas[i];
        }
    }

    if (contaOrigem && contaDestino)
        TransferenciaConta(contaDestino, contaOrigem, valor);
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContas; i++)
        ImprimeConta(banco->contas[i]);
}