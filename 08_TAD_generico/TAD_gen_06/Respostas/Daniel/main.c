#include "numcomplexo.h"
#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void TabelaImprimeMatriz(tMatrizGenerica *mat, int dataType);

int main() {
    int rows, cols, dataType;
    tMatrizGenerica *mat;

    printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): \n");

    // Reading the matrix dimensions and data type
    if (scanf("%d %d %d", &rows, &cols, &dataType) != 3) {
        printf("Error reading matrix dimensions and data type\n");
        return 1;
    }

    switch (dataType) {
        case 0: // Integer
            mat = readMatrix(rows, cols, sizeof(int), readInt);
            break;
        case 1: // Float
            mat = readMatrix(rows, cols, sizeof(float), readFloat);
            break;
        case 2: // Double
            mat = readMatrix(rows, cols, sizeof(double), readDouble);
            break;
        case 3: // Char
            mat = readMatrix(rows, cols, sizeof(char), readChar);
            break;
        case 4: // Complex
            mat = readMatrix(rows, cols, RetornaNumBytesComplexo(), readComplex);
            break;
        default:
            printf("Invalid data type\\n");
            return 1;
    }

    printf("Digite a operação desejada\n");
    printf("\t1 - Apenas imprimir a matriz\n");
	printf("\t2 - Converter para o tipo complexo e imprimir");
	printf("\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.");

    int op;

    while (true) {
        if (scanf("%d", &op) != 1) {
            printf("Error reading operation\n");
            DestroiMatrizGenerica(mat);
            return 1;
        }

        switch (op) {
            case 1:
                TabelaImprimeMatriz(mat, dataType);
                break;
            case 2:
                // Convert to complex
                break;
            case 3:
                // Multiply by its transpose
                break;
            default:
                printf("Invalid operation\\n");
                DestroiMatrizGenerica(mat);
                return 1;
        }
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
    printf("%.2f + i%.2f", PegaParteRealComplexo(cplx), PegaParteImagComplexo(cplx));
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

void TabelaImprimeMatriz(tMatrizGenerica *mat, int dataType) {
    switch (dataType) {
        case 0: // Integer
            printMatrix(mat, printInt, ImprimirMatrizGenerica);
            break;
        case 1: // Float
            printMatrix(mat, printFloat, ImprimirMatrizGenerica);
            break;
        case 2: // Double
            printMatrix(mat, printDouble, ImprimirMatrizGenerica);
            break;
        case 3: // Char
            printMatrix(mat, printChar, ImprimirMatrizGenerica);
            break;
        case 4: // Complex
            printMatrix(mat, printComplex, ImprimirMatrizGenerica);
            break;
        default:
            printf("Invalid data type\\n");
    }
}