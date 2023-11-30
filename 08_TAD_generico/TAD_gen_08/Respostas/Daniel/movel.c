#include "movel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARACTERS 31

struct Movel {
    char nome[MAX_CARACTERS];
};

tMovel *CriaMovel(char *nome) {
    if (!nome) {
        printf("Erro: Nome eh NULL\n");
        exit(EXIT_FAILURE);
    }

    tMovel *m = (tMovel*) calloc(1, sizeof(tMovel));
    if (!m) {
        printf("Erro ao alocar memoria para movel\n");
        exit(EXIT_FAILURE);
    }

    strcpy(m->nome, nome);
    return m;
}

void DestroiMovel(tMovel *m) {
    if (!m) {
        printf("Erro: Esta tentando liberar um struct NULL\n");
        exit(EXIT_FAILURE);
    }
    free(m);
}

tMovel *LeMovel() {
    char nome[MAX_CARACTERS];
    scanf(" %s", nome);
    return CriaMovel(nome);
}

void ImprimeMovel(tMovel *m) {
    if (!m) {
        printf("Erro: Movel eh NULL\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", m->nome);
}