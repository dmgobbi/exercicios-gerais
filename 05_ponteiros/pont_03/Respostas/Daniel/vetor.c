#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] < *paraTrocar) {
            int aux = vet[i];
            vet[i] = *paraTrocar;
            *paraTrocar = aux;
        }
    }
}

void OrdeneCrescente(int * vet, int tam) {
    for (int i = 0; i < tam; i++) {
        TrocaSeAcharMenor(&vet[i], tam - i, &vet[i]);
    }
}
