#include "banco.h"
#include "agencia.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Banco {
    char *nome;
    Vector *agencias;
    int numAgencias;
};

tBanco *CriaBanco() {
    tBanco *banco = calloc(1, sizeof(tBanco));
    if (banco == NULL) {
        printf("Erro ao alocar memória para o banco.\n");
        exit(EXIT_FAILURE);
    }
    banco->agencias = VectorConstruct();
    return banco;
}

void DestroiBanco(tBanco *banco) {
    free(banco->nome);
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco);
}

void LeBanco(tBanco *banco) {
    char nome[100];
    scanf("%[^\n]\n", nome);
    banco->nome = strdup(nome);
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {
    VectorPushBack(banco->agencias, agencia);
    banco->numAgencias++;
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente) {
    for (int i = 0; i < banco->numAgencias; i++) {
        tAgencia *agencia = (tAgencia *) VectorGet(banco->agencias, i);
        if (ComparaAgencia(numAgencia, agencia)) {
            AdicionaConta(agencia, cliente);
            return;
        }
    }
    printf("Agencia nao encontrada.\n");
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for (int i = 0; i < banco->numAgencias; i++) {
        tAgencia *agencia = (tAgencia *) VectorGet(banco->agencias, i);
        ImprimeDadosAgencia(agencia);
        printf("\n");
    }
}