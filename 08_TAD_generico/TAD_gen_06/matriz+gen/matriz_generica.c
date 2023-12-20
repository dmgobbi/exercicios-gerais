#include "matriz_generica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tMatrizGenerica{
	int linhas;
	int colunas;
    int numByteElem; //Tamanho do elemento generico em bytes
	void*elementos;
};

tMatrizGenerica* CriaMatrizGenerica(int linhas, int colunas, int numByteElem){
	tMatrizGenerica * mat = malloc(sizeof(tMatrizGenerica));
    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->numByteElem = numByteElem;
	mat->elementos = calloc(mat->linhas*mat->colunas, numByteElem);
	return mat;
}

void FinalizaMatrizGenerica(tMatrizGenerica * mat){
    free(mat->elementos);
    free(mat);
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat){
    return mat->linhas;
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat){
    return mat->colunas;
}

void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna){
    //Faz o salto para a posicao correta de memoria contabilizando o tamanho do elemento
    return mat->elementos + (linha*(mat->colunas*mat->numByteElem) + (coluna*mat->numByteElem));
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem){
    //Copia o elemento informado para a posicao desejada
    void * elemMat = ObtemElementoMatrizGenerica(mat, linha, coluna);
    memcpy(elemMat, elem, mat->numByteElem);
}

void EspelharHorizontalMatrizGenerica(tMatrizGenerica * mat){
    void * elemMat1;
    void * elemMat2;
    //reserva memoria para um elemento
    char elemento[mat->numByteElem];
    for(int i = 0; i < mat->linhas/2; i++){
        for(int j = 0; j < mat->colunas; j++){
            elemMat1 = ObtemElementoMatrizGenerica(mat, i, j);
            elemMat2 = ObtemElementoMatrizGenerica(mat, mat->linhas-1-i, j);
            //Troca elementos
            memcpy(elemento, elemMat1, mat->numByteElem);
            memcpy(elemMat1, elemMat2, mat->numByteElem);
            memcpy(elemMat2, elemento, mat->numByteElem);
        }        
    }
}

void EspelharVerticalMatrizGenerica(tMatrizGenerica * mat){
    void * elemMat1;
    void * elemMat2;
    //reserva memoria para um elemento
    char elemento[mat->numByteElem];
    for(int j = 0; j < mat->colunas/2; j++){
        for(int i = 0; i < mat->linhas; i++){
            elemMat1 = ObtemElementoMatrizGenerica(mat, i, j);
            elemMat2 = ObtemElementoMatrizGenerica(mat, i, mat->colunas-1-j);
            //Troca elementos
            memcpy(elemento, elemMat1, mat->numByteElem);
            memcpy(elemMat1, elemMat2, mat->numByteElem);
            memcpy(elemMat2, elemento, mat->numByteElem);
        }        
    }
}

void SomaMatrizGenerica(tMatrizGenerica * mat1, tMatrizGenerica * mat2, tMatrizGenerica * mat3, FptrSoma funcSoma){
    void * elemMat1;
    void * elemMat2;
    void * elemMat3;
    //Faz a soma de cada elemento usando a funcao informada
    for(int i = 0; i < mat1->linhas; i++){
        for(int j = 0; j < mat1->colunas; j++){
            elemMat1 = ObtemElementoMatrizGenerica(mat1, i, j);
            elemMat2 = ObtemElementoMatrizGenerica(mat2, i, j);
            elemMat3 = ObtemElementoMatrizGenerica(mat3, i, j);
            funcSoma(elemMat1, elemMat2, elemMat3);
        }        
    }
}
