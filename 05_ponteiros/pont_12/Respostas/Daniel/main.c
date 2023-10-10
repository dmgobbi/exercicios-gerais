#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int Soma(int x, int y);
int Produto(int x, int y);

int main() {
    Vetor vetor;
    LeVetor(&vetor);

    int resultadoSoma = AplicarOperacaoVetor(&vetor, Soma);
    int resultadoProduto = AplicarOperacaoVetor(&vetor, Produto);

    printf("Soma: %d\n", resultadoSoma);
    printf("Produto: %d\n", resultadoProduto);

    return 0;
}

int Soma(int x, int y) {
    return x + y;
}

int Produto(int x, int y) {
    return x * y;
}
