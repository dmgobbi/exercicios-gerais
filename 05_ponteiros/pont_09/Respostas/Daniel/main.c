#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    int qtdPessoas;
    scanf("%d", &qtdPessoas);

    tPessoa pessoa[qtdPessoas];

    for (int i = 0; i < qtdPessoas; i++) {
        *(pessoa + i) = CriaPessoa();
        LePessoa(pessoa + i);

        // pessoa[i] = CriaPessoa();
        // LePessoa(&pessoa[i]);
    }

    AssociaFamiliasGruposPessoas(pessoa);
    
    for (int i = 0; i < qtdPessoas; i++) {
        ImprimePessoa(pessoa + i);       
        //ImprimePessoa(&pessoa[i]);
    }

    return 0;
}
