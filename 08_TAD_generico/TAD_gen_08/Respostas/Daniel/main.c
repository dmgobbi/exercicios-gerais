#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
#include "movel.h"
#include "vector.h"

#define MAX_STR 20
#define ENTRADA "ENTRADA"
#define PRODUZIR "PRODUZIR"

int main () {
    char operacao[MAX_STR];
    int numOperacoes;

    scanf(" %d", &numOperacoes);

    Fila* f = FilaConstruct();

    for (int i = 0; i < numOperacoes; i++) {
        scanf(" %s", operacao);
        if (!strcmp(operacao, ENTRADA)) {
            tMovel* m = LeMovel();
            FilaPush(f, m);
        }
        else if (!strcmp(operacao, PRODUZIR)) {
            tMovel* m = (tMovel*) FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }

    FilaDestroy(f, DestroiMovel);
    return 0;
}
