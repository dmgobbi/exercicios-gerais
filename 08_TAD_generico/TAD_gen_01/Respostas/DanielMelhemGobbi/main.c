#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main() {
    int tipo, numElem;

    scanf("%d %d", &tipo, &numElem);

    tGeneric *gen = CriaGenerico((Type)tipo, numElem);

    if (gen == NULL) {
        printf("Erro na criacao do vetor generico.\n");
        return 1;
    }

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");

    LeGenerico(gen);

    ImprimeGenerico(gen);

    DestroiGenerico(gen);

    return 0;
}
