#include "numcomplexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct complexo {
    float real;
    float imag;
};

tNumComplexo* CriaNumComplexo(float real, float imag) {
    tNumComplexo *cplx = (tNumComplexo*) malloc(sizeof(tNumComplexo));
    if (cplx == NULL) {
        printf("Erro ao alocar memória para o número complexo\n");
        exit(1);
    }
    cplx->real = real;
    cplx->imag = imag;
    return cplx;
}

float PegaParteImagComplexo(tNumComplexo *cplx) {
    return cplx->imag;
}

float PegaParteRealComplexo(tNumComplexo *cplx) {
    return cplx->real;
}

void ImprimeNumeroComplexo(tNumComplexo *cplx) {
    printf("%.2f + i%.2f", cplx->real, cplx->imag);
}

void DestroiNumeroComplexo(tNumComplexo *cplx) {
    free(cplx);
}

int RetornaNumBytesComplexo() {
    return sizeof(struct complexo);
}

tNumComplexo* SomaComplexos(tNumComplexo* n1, tNumComplexo *n2) {
    float real = n1->real + n2->real;
    float imag = n1->imag + n2->imag;
    tNumComplexo *cplx = CriaNumComplexo(real, imag);
    return cplx;
}

tNumComplexo* MultComplexos(tNumComplexo* n1, tNumComplexo* n2) {
    float real = (n1->real * n2->real) - (n1->imag * n2->imag);
    float imag = (n1->real * n2->imag) + (n1->imag * n2->real);
    tNumComplexo *cplx = CriaNumComplexo(real, imag);
    return cplx;
}
