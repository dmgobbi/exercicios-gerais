#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    data_type *vetor; 
    int tamanho;        
};

Vector *VectorConstruct() {
    Vector *v = (Vector *) calloc(1, sizeof(Vector));
    if (!v) {
        printf("Erro na alocacao de memoria para o vetor.\n");
        exit(EXIT_FAILURE);
    }
    return v;
}

void VectorPushBack(Vector *v, data_type val) {
    if (!v) {
        printf("Erro: vetor nao inicializado.\n");
        exit(EXIT_FAILURE);
    }

    v->tamanho++;

    if (!v->tamanho) v->vetor = (data_type *) calloc(1, sizeof(data_type));
    else v->vetor = (data_type *) realloc(v->vetor, v->tamanho * sizeof(data_type));

    v->vetor[v->tamanho - 1] = val;
}

data_type VectorGet(Vector *v, int i) {
    if (!v) {
        printf("Erro: vetor nao inicializado.\n");
        exit(EXIT_FAILURE);
    }

    if (i < 0 || i >= v->tamanho) {
        printf("Indice fora dos limites do vetor.\n");
        exit(EXIT_FAILURE);
    }

    return v->vetor[i];
}

int VectorSize(Vector *v) {
    if (!v) {
        printf("Erro: vetor eh NULL.\n");
        exit(EXIT_FAILURE);
    }

    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    if (!v) {
        printf("Erro: vetor eh NULL.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < VectorSize(v); i++) {
        if (!v->vetor[i]) {
            printf("Erro: vetor[%d] eh NULL.\n", i);
            exit(EXIT_FAILURE);
        }
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}
