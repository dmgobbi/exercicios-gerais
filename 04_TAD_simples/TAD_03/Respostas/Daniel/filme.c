#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade) {
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    return filme;
}

tFilme lerFilme () {
    tFilme filme;
    int codigo, valor, quantidade;
    char nome[MAX_CARACTERES];

    if (scanf("%d,%[^,],%d,%d", &codigo, nome, &valor, &quantidade) != 4) {
        printf("Erro ao ler filme\n");
        filme.codigo = -1;
        return filme;
    }

    filme = criarFilme(nome, codigo, valor, quantidade);
    return filme;
}

int obterCodigoFilme (tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme) {
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme) {
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo) {
    return filme.codigo == codigo;
}

tFilme alugarFilme (tFilme filme) {
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme (tFilme filme) {
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2) {
    return strcmp(filme1.nome, filme2.nome);
}
