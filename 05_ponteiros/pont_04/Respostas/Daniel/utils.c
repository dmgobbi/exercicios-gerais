#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LeNumeros(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
        //scanf("%d", array + i);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media) {
    for (int i = 0; i < tamanho; i++) {
        if (!i) {
            *maior = array[i];
            *menor = array[i];
            *media = 0;
        } else {
            if (array[i] > *maior) {
                *maior = array[i];
            } else if (array[i] < *menor) {
                *menor = array[i];
            }
        }
        *media += array[i];
    }
    *media /= tamanho;
}
