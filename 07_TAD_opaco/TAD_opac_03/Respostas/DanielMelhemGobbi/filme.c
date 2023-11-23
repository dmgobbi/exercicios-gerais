#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

struct Filme {
    int codigo;
    char nome[MAX_CARACTERES];
    int valor;
    int qtdEstoque;
    int qtdAlugada;
};

tFilme* CriarFilme () {
    tFilme* filme = (tFilme*) malloc(sizeof(tFilme));
    
    if (filme == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }
    
    filme->codigo = 0;
    filme->nome[0] = '\0';
    filme->valor = 0;
    filme->qtdEstoque = 0;
    filme->qtdAlugada = 0;
    
    return filme;
}

void LeFilme (tFilme* filme, int codigo) {
    int valor, quantidade;
    char nome[MAX_CARACTERES];

    if (scanf(" %[^,],%d,%d", nome, &valor, &quantidade) != 3) {
        printf("Erro ao ler filme\n");
        exit(1);
    }

    filme->codigo = codigo;
    strcpy(filme->nome, nome);
    filme->valor = valor;
    filme->qtdEstoque = quantidade;
}

void DestruirFilme (tFilme* filme) {
    free(filme);
}

int ObterCodigoFilme (tFilme* filme) {
    return filme->codigo;
}
    
void ImprimirNomeFilme (tFilme* filme) {
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme) {
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme) {
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme) {
    return filme->qtdAlugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo) {
    return filme->codigo == codigo;
}

void AlugarFilme (tFilme* filme) {
    filme->qtdAlugada++;
    filme->qtdEstoque--;
}

void DevolverFilme (tFilme* filme) {
    filme->qtdAlugada--;
    filme->qtdEstoque++;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2) {
    return strcmp(filme1->nome, filme2->nome);
}
