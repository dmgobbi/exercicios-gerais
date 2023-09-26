#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main(void) {
    char operacao[20];
    tLocadora locadora = criarLocadora();

    while (1) {
        scanf("%s", operacao);
         
        if (!strcmp(operacao, "Cadastrar")) {
            locadora = lerCadastroLocadora(locadora);
            locadora = ordenarFilmesLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(operacao, "Alugar")) {
            locadora = lerAluguelLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(operacao, "Devolver")) {
            locadora = lerDevolucaoLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(operacao, "Estoque")) {
            consultarEstoqueLocadora(locadora);
            scanf("%*[^#]#");
        }else {
            break;
        }

        *operacao = '\0';
    }
    
    consultarLucroLocadora(locadora);

    return 0;
}
