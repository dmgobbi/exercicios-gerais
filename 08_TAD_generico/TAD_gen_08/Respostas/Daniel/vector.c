#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    DataType *vetor; 
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

void VectorPushBack(Vector *v, DataType val) {
    if (!v) {
        printf("Erro: vetor nao inicializado.\n");
        exit(EXIT_FAILURE);
    }
    v->tamanho++;
    v->vetor = (DataType *) realloc(v->vetor, v->tamanho * sizeof(DataType));
    v->vetor[v->tamanho - 1] = val;
}

DataType VectorPopFront(Vector *v) {
    if (!v) {
        printf("Erro: vetor nao inicializado.\n");
        exit(EXIT_FAILURE);
    }
    DataType val = v->vetor[0];
    for (int i = 1; i < v->tamanho; i++) v->vetor[i - 1] = v->vetor[i];
    v->tamanho--;
    return val;
}

DataType VectorGet(Vector *v, int i) {
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

void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    if (!v) {
        printf("Erro: vetor eh NULL.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < v->tamanho; i++) {
        if (!v->vetor[i]) {
            printf("Erro: vetor[%d] eh NULL.\n", i);
            exit(EXIT_FAILURE);
        }
        destroy(v->vetor[i]);
    }
    
    free(v->vetor);
    free(v);
}
