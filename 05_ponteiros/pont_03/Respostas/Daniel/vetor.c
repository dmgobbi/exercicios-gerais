#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
        // scanf("%d", vet + i);
    }
}

void ImprimeDadosDoVetor(int * n, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar) {
    int menor = vet[*paraTrocar];
    int indexMenor = *paraTrocar;

    for (int i = *paraTrocar; i < tam; i++) {
        if (vet[i] < menor) {
            menor = vet[i];
            indexMenor = i;
        }
    }

    if (indexMenor != *paraTrocar) {
        int aux = vet[*paraTrocar];
        vet[*paraTrocar] = vet[indexMenor];
        vet[indexMenor] = aux;

        *paraTrocar = indexMenor;
    }
}

void OrdeneCrescente(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        int indexMenor = i;
        TrocaSeAcharMenor(vet, tam, &indexMenor);
    }
}
