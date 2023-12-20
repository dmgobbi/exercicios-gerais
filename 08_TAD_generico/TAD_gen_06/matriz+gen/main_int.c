#include "matriz_generica.h"
#include <stdio.h>
#include <stdlib.h>
#define TIPO_ELEMENTO int


int main() {
    TIPO_ELEMENTO elem;
	int linhas, colunas;
    scanf("%d%d", &linhas, &colunas);
	tMatrizGenerica * mat = CriaMatrizGenerica(linhas, colunas, sizeof(TIPO_ELEMENTO));
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++){
            scanf("%d", &elem);
            AtribuiElementoMatrizGenerica(mat, i, j, &elem);
        }        
    }
    
    EspelharVerticalMatrizGenerica(mat);
    
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++){
            TIPO_ELEMENTO * elem = (TIPO_ELEMENTO*)ObtemElementoMatrizGenerica(mat, i, j);
            printf("%d ", *elem);
        }        
        printf("\n");
    }
    
    FinalizaMatrizGenerica(mat);
	
    return 0;
}