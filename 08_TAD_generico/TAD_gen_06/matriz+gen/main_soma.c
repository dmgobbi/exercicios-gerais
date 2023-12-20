#include "matriz_generica.h"
#include <stdio.h>
#include <stdlib.h>
#define TIPO_ELEMENTO double

void Soma(void* elem1, void* elem2, void* elem3){
    TIPO_ELEMENTO * elemMat1 = elem1;
    TIPO_ELEMENTO * elemMat2 = elem2;
    TIPO_ELEMENTO * elemMat3 = elem3;
    
    *elemMat3 = *elemMat1 + *elemMat2;
}

int main() {
    TIPO_ELEMENTO elem;
	int linhas, colunas;
    scanf("%d%d", &linhas, &colunas);
    //Cria as 3 matrizes
	tMatrizGenerica * mat1 = CriaMatrizGenerica(linhas, colunas, sizeof(TIPO_ELEMENTO));
	tMatrizGenerica * mat2 = CriaMatrizGenerica(linhas, colunas, sizeof(TIPO_ELEMENTO));
	tMatrizGenerica * mat3 = CriaMatrizGenerica(linhas, colunas, sizeof(TIPO_ELEMENTO));
    //Preenche as matrizes 1 e 2 com a mesma entrada
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat1); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat1); j++){
            scanf("%lf", &elem);
            AtribuiElementoMatrizGenerica(mat1, i, j, &elem);
            AtribuiElementoMatrizGenerica(mat2, i, j, &elem);
        }        
    }

    //Altera a matriz 1 com espelhamento vertical e horizontal
    EspelharHorizontalMatrizGenerica(mat1);
    EspelharVerticalMatrizGenerica(mat1);
    //Soma as matrizes 1 e 2 e coloca em 3
    SomaMatrizGenerica(mat1, mat2, mat3, Soma);
    
    //Imprime a matriz 1
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat1); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat1); j++){
            TIPO_ELEMENTO * elem = (TIPO_ELEMENTO*)ObtemElementoMatrizGenerica(mat1, i, j);
            printf("%.2lf ", *elem);
        }        
        printf("\n");
    }
    printf("\n");

    //Imprime a matriz 2
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat2); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat2); j++){
            TIPO_ELEMENTO * elem = (TIPO_ELEMENTO*)ObtemElementoMatrizGenerica(mat2, i, j);
            printf("%.2lf ", *elem);
        }        
        printf("\n");
    }
    printf("\n");

    //Imprime a matriz 3
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat3); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat3); j++){
            TIPO_ELEMENTO * elem = (TIPO_ELEMENTO*)ObtemElementoMatrizGenerica(mat3, i, j);
            printf("%.2lf ", *elem);
        }        
        printf("\n");
    }
    
    //Libera as matrizes 1, 2 e 3 
    FinalizaMatrizGenerica(mat1);
    FinalizaMatrizGenerica(mat2);
    FinalizaMatrizGenerica(mat3);
	
    return 0;
}