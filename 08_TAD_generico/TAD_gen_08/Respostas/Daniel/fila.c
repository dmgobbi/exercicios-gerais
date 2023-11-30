#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct Fila {
    Vector *vetorFila;
};

Fila *FilaConstruct() {
    Fila* f = (Fila *) calloc(1, sizeof(Fila));
    if (!f) {
        printf("Erro na alocacao de memoria da fila\n");
        exit(EXIT_FAILURE);
    }
    f->vetorFila = VectorConstruct();
    return f;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)) {
    if (!f || !*destroy) {
        printf("Erro: struct fila ou fcprt destroy eh NULL\n");
        exit(EXIT_FAILURE);
    }
    VectorDestroy(f->vetorFila, destroy);
    free(f);
}

int FilaSize(Fila *f) {
    if (!f) {
        printf("Erro: struct fila eh NULL\n");
        exit(EXIT_FAILURE);
    }
    return VectorSize(f->vetorFila);
}

DataType FilaPop(Fila *f) {
    if (!f) {
        printf("Erro: struct fila eh NULL\n");
        exit(EXIT_FAILURE);
    }
    return VectorPopFront(f->vetorFila);
}

void FilaPush(Fila *f, DataType val)  {
    if (!f || !val) {
        printf("Erro: struct fila ou val eh NULL\n");
        exit(EXIT_FAILURE);
    }
   VectorPushBack(f->vetorFila, val);
}