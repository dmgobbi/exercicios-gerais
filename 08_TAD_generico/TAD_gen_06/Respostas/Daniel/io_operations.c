#include "io_operations.h"
#include "numcomplexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void readInt(void *elem) {
    scanf("%d", (int *)elem);
}

void printInt(void *elem) {
    printf("%d", *(int *)elem);
}

void readFloat(void *elem) {
    scanf("%f", (float *)elem);
}

void printFloat(void *elem) {
    printf("%.2f", *(float *)elem);
}

void readDouble(void *elem) {
    scanf("%lf", (double *)elem);
}

void printDouble(void *elem) {
    printf("%.2lf", *(double *)elem);
}

void readChar(void *elem) {
    scanf(" %c", (char *)elem);
}

void printChar(void *elem) {
    printf("%c", *(char *)elem);
}

void readComplex(void *elem) {
    float real, imag;
    scanf(" (%f,%f)", &real, &imag);
    tNumComplexo *cplx = CriaNumComplexo(real, imag);
    memcpy(elem, cplx, RetornaNumBytesComplexo());
    DestroiNumeroComplexo(cplx);
}

void printComplex(void *elem) {
    tNumComplexo *cplx = (tNumComplexo *)elem;
    printf("%.2f + i%.2f", PegaParteRealComplexo(cplx), PegaParteImagComplexo(cplx));
}
