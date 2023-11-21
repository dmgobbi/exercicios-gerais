#include "circulo.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

struct circulo {
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r) {
    tCirculo c = (tCirculo) malloc(sizeof(struct circulo));
    if (!c) {
        printf("Erro ao alocar memoria para circulo.\n");
        return NULL;
    }
    c->centro = Pto_Cria(x, y);
    c->raio = r;
    return c;
}

void Circulo_Apaga (tCirculo c) {
    if (c != NULL) {
        Pto_Apaga(c->centro);
        free(c);
    }
}

tPonto Circulo_Acessa_Centro (tCirculo c) {
    if (c != NULL) return c->centro;
    return NULL; 
}

float Circulo_Acessa_Raio (tCirculo c) {
    if (c != NULL) return c->raio;
    return 0; 
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p) {
    if (c != NULL && p != NULL) c->centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r) {
    if (c != NULL) c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p) {
    if (c != NULL && p != NULL) {
        float distancia = Pto_Distancia(c->centro, p);
        return distancia <= c->raio;
    }
    return 0; 
}
