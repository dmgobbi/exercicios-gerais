#include "matriz_generica.h"
#include <stdio.h>
#include <stdlib.h>
#define TIPO_ELEMENTO double

int main() {
    TIPO_ELEMENTO elem;
	int linhas, colunas;
    scanf("%d%d", &linhas, &colunas);
	tMatrizGenerica * mat = CriaMatrizGenerica(linhas, colunas, sizeof(TIPO_ELEMENTO));
    //Le matriz da entrada padrao
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++){
            scanf("%lf", &elem);
            AtribuiElementoMatrizGenerica(mat, i, j, &elem);
        }        
    }

    //Faz espelhamentos
    EspelharHorizontalMatrizGenerica(mat);
    EspelharVerticalMatrizGenerica(mat);
    
    //Imprime matriz na saida padrao
    for(int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++){
        for(int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++){
            TIPO_ELEMENTO * elem = (TIPO_ELEMENTO*)ObtemElementoMatrizGenerica(mat, i, j);
            printf("%.2lf ", *elem);
        }        
        printf("\n");
    }
    
    FinalizaMatrizGenerica(mat);
	
    return 0;
}