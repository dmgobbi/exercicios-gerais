#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    float x;
    float y;
};

tPonto Pto_Cria (float x, float y) {
    tPonto p = (tPonto) malloc(sizeof(struct ponto));
    if (!p) {
        printf("Erro ao alocar memoria para ponto.\n");
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

void Pto_Apaga (tPonto p) {
    free(p);
}

float Pto_Acessa_x (tPonto p) {
    if (p != NULL) return p->x;
    return 0; 
}

float Pto_Acessa_y (tPonto p) {
    if (p != NULL) return p->y;
    return 0; 
}

void Pto_Atribui_x (tPonto p, float x) {
    if (p != NULL) p->x = x;
}

void Pto_Atribui_y (tPonto p, float y) {
    if (p != NULL) p->y = y;
}

float Pto_Distancia (tPonto p1, tPonto p2) {
    if (p1 != NULL && p2 != NULL) {
        float dx = p1->x - p2->x;
        float dy = p1->y - p2->y;
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
    return 0; 
}
