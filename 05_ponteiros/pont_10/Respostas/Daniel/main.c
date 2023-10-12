#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    int numPessoas;
    scanf("%d", &numPessoas);

    tPessoa pessoa[numPessoas];

    for (int i = 0; i < numPessoas; i++) {
        *(pessoa + i) = CriaPessoa();
        LePessoa(pessoa + i);

        // pessoa[i] = CriaPessoa();
        // LePessoa(&pessoa[i]);
    }

    AssociaFamiliasGruposPessoas(pessoa, numPessoas);
    
    for (int i = 0; i < numPessoas; i++) {
        ImprimePessoa(pessoa + i);       
        //ImprimePessoa(&pessoa[i]);
    }

    return 0;
}
