#ifndef _MATRIZ_GENERICA_H
#define _MATRIZ_GENERICA_H

typedef void (*FptrSoma)(void* elem1, void* elem2, void* elem3);

typedef struct _tMatrizGenerica tMatrizGenerica;

//Cria uma Matriz Generica baseado no numero de linhas e colunas e no tamanho do elemento a ser armazenado
tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem);

//Finaliza uma Matriz Generica
void FinalizaMatrizGenerica(tMatrizGenerica * mat);

//Obtem numero de linhas da Matriz Generica
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat);

//Obtem numero de colunas da Matriz Generica
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat);

//Obtem o endereco de um elemento da Matriz Generica
void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna);

//Atribui um elemento a Matriz Generica
void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem);

//Imprime elementos da matriz
void ImprimeMatrizGenerica(tMatrizGenerica * mat);

//Espelha a matriz horizontalmente
void EspelharHorizontalMatrizGenerica(tMatrizGenerica * mat);

//Espelha a matriz verticalmente
void EspelharVerticalMatrizGenerica(tMatrizGenerica * mat);

//Soma elemento a elemento das matrizes 1 e 2 e coloca na 3 matrizes
void SomaMatrizGenerica(tMatrizGenerica * mat1, tMatrizGenerica * mat2, tMatrizGenerica * mat3, FptrSoma funcSoma);

#endif
