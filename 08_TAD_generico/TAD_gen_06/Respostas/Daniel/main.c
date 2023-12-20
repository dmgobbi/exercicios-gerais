#include "numcomplexo.h"
#include "matrizgenerica.h"
#include "io_operations.h"
#include "screens.h"
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

void TabelaImprimeMatriz(tMatrizGenerica *mat, int dataType);
tMatrizGenerica* TabelaConverteMatrizParaComplexo(tMatrizGenerica *mat, int dataType);

int main() {
    int rows, cols, dataType;
    tMatrizGenerica *mat;

    // Reading the matrix dimensions and data type
    promptMatrixDetailsInput();
    if (scanf("%d %d %d", &rows, &cols, &dataType) != 3) {
        printf("Error reading matrix dimensions and data type\n");
        return EXIT_FAILURE;
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
            return EXIT_FAILURE;
    }

    int op = promptMatrixOperationChoice();

    switch (op) {
        case 1: // Print
            TabelaImprimeMatriz(mat, dataType);
            break;
        case 2: // Convert to complex and print
            tMatrizGenerica *cplxMat = TabelaConverteMatrizParaComplexo(mat, dataType);
            printMatrix(cplxMat, printComplex, ImprimirMatrizGenerica);
            DestroiMatrizGenerica(cplxMat);
            break;
        case 3:
            // Convert to complex
            // multiply by its transpose
            // print the result
            break;
        default:
            printf("Invalid operation\\n");
            DestroiMatrizGenerica(mat);
            return EXIT_FAILURE;
    }

    op = promptEndOrContinue();

    switch (op) {
        case 1:
            // TODO: Continue (read new matrix)
            break;
        case 2:
            // End
            DestroiMatrizGenerica(mat);
            return EXIT_SUCCESS;
        default:
            printf("Invalid operation\\n");
            DestroiMatrizGenerica(mat);
            return EXIT_FAILURE;
    }

    DestroiMatrizGenerica(mat);

    return EXIT_SUCCESS;
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
            printf("Invalid data type\n");
    }
}

// Recebe uma matriz generica qualquer e um tipo de dado e a converte para uma matriz de complexos
tMatrizGenerica* TabelaConverteMatrizParaComplexo(tMatrizGenerica *mat, int dataType) {
    tMatrizGenerica *cplxMat = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat), ObtemNumeroColunasMatrizGenerica(mat), RetornaNumBytesComplexo());
    if (!cplxMat) {
        printf("Error creating matrix\n");
        exit(1);
    }

    // Usando a funcao 'tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*))' para converter a matriz generica para uma matriz de complexos 
    switch (dataType) {
        case 0: // Integer
            cplxMat = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteIntParaComplexo);
            break;
        case 1: // Float
            cplxMat = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteFloatParaComplexo);
            break;
        case 2: // Double
            cplxMat = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteDoubleParaComplexo);
            break;
        case 3: // Char
            cplxMat = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteCharParaComplexo);
            break;
        case 4: // Complex
            break;      
        default:
            printf("Invalid data type\n"); 
    }
    return cplxMat;
}