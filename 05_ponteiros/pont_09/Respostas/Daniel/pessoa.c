#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    char nome[100];
    scanf(" %99[^\n]\n", nome);
    strcpy(pessoa->nome, nome);
    // scanf(" %99[^\n]\n", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    return pessoa->pai != NULL || pessoa->mae != NULL;
}

void ImprimePessoa(tPessoa *pessoa) {
    if (!VerificaSeTemPaisPessoa(pessoa)) {
        return;
    }

    printf("NOME COMPLETO: %s\n", pessoa->nome);

    tPessoa *pPai = pessoa->pai;
    tPessoa *pMae = pessoa->mae;

    if (pPai != NULL) {
        printf("PAI: %s\n", pPai->nome);
    } else {
        printf("PAI: NAO INFORMADO\n");
    }

    if (pMae != NULL) {
        printf("MAE: %s\n", pMae->nome);
    } else {
        printf("MAE: NAO INFORMADO\n");
    }

    // char *nomePai = (pPai != NULL) ? pPai->nome : "NAO INFORMADO\n";
    // char *nomeMae = (pMae != NULL) ? pMae->nome : "NAO INFORMADO\n";

    // printf("PAI: %s\n", nomePai);
    // printf("MAE: %s\n", nomeMae);

    printf("\n");
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int qtdAssociacoes;
    int x, y, z;
    
    scanf("%d", &qtdAssociacoes);

    for (int i = 0; i < qtdAssociacoes; i++) {
        scanf(" mae: %d, pai: %d, filho: %d", &x, &y, &z);

        tPessoa *pFilho = (pessoas + z);
        
        if (x != -1) {
            pFilho->mae = (pessoas + x);
            // pessoas[z].mae = (pessoas + x);
            // (pessoas + z)->mae = (pessoas + x);

        } 

        if (y != -1) {
            pFilho->pai = (pessoas + y);
            // pessoas[z].pai = (pessoas + y);
            // (pessoas + z)->pai = (pessoas + y);
        } 
    }
}
