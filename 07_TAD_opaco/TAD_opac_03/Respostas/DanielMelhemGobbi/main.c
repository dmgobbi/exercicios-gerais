#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main(void) {
    char operacao[20];
    tLocadora* locadora = CriarLocadora();

    while (1) {
        scanf("%s", operacao);
         
        if (!strcmp(operacao, "Cadastrar")) {
            LerCadastroLocadora(locadora);
            OrdenarFilmesLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(operacao, "Alugar")) {
            LerAluguelLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(operacao, "Devolver")) {
            LerDevolucaoLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(operacao, "Estoque")) {
            ConsultarEstoqueLocadora(locadora);
            scanf("%*[^#]#");
        }else {
            break;
        }

        *operacao = '\0';
    }
    
    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);

    return 0;
}
