#include "numcomplexo.h"
#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Callback function types for reading and printing elements
typedef void (*ReadElementFunc)(void *);
typedef void (*PrintElementFunc)(void *);
typedef void (*PrintMatrixFunc)(tMatrizGenerica *, PrintElementFunc);

// Function prototypes
tMatrizGenerica* readMatrix(int rows, int cols, int elemSize, ReadElementFunc readElem);
void printMatrix(tMatrizGenerica *mat, PrintElementFunc printElem, PrintMatrixFunc printMat);

void readInt(void *elem);
void printInt(void *elem);
void readFloat(void *elem);
void printFloat(void *elem);
void readDouble(void *elem);
void printDouble(void *elem);
void readChar(void *elem);
void printChar(void *elem);
void readComplex(void *elem);
void printComplex(void *elem);

int main() {
    int rows, cols, dataType;
    tMatrizGenerica *mat;

    // Reading the matrix dimensions and data type
    scanf("%d %d %d", &rows, &cols, &dataType);

    switch (dataType) {
        case 0: // Integer
            mat = readMatrix(rows, cols, sizeof(int), readInt);
            printMatrix(mat, printInt, ImprimirMatrizGenerica);
            break;
        case 1: // Float
            mat = readMatrix(rows, cols, sizeof(float), readFloat);
            printMatrix(mat, printFloat, ImprimirMatrizGenerica);
            break;
        case 2: // Double
            mat = readMatrix(rows, cols, sizeof(double), readDouble);
            printMatrix(mat, printDouble, ImprimirMatrizGenerica);
            break;
        case 3: // Char
            mat = readMatrix(rows, cols, sizeof(char), readChar);
            printMatrix(mat, printChar, ImprimirMatrizGenerica);
            break;
        case 4: // Complex
            mat = readMatrix(rows, cols, RetornaNumBytesComplexo(), readComplex);
            printMatrix(mat, printComplex, ImprimirMatrizGenerica);
            break;
        default:
            printf("Invalid data type\\n");
    }

    DestroiMatrizGenerica(mat);

    return 0;
}

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
    printf("(%.2f,%.2f)", PegaParteRealComplexo(cplx), PegaParteImagComplexo(cplx));
}

tMatrizGenerica* readMatrix(int rows, int cols, int elemSize, ReadElementFunc readElem) {
    tMatrizGenerica *mat = CriaMatrizGenerica(rows, cols, elemSize);
    if (!mat) {
        printf("Error creating matrix\\n");
        exit(1);
    }

    for (int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for (int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            readElem(ObtemElementoMatrizGenerica(mat, i, j));
        }
    }

    return mat;
}

void printMatrix(tMatrizGenerica *mat, PrintElementFunc printElem, PrintMatrixFunc printMat) {
    printMat(mat, printElem);
}