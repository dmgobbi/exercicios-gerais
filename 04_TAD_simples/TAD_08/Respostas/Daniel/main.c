#include <stdio.h>
#include "departamento.h"

int main() {
    int N;
    scanf("%d", &N);
    tDepartamento depto[N];

    for (int i = 0; i < N; i++) {
        scanf(" %s", depto[i].nome);
        scanf(" %s", depto[i].diretor);
        scanf(" %s %s %s", depto[i].c1, depto[i].c2, depto[i].c3);
        scanf(" %d %d %d", &depto[i].m1, &depto[i].m2, &depto[i].m3);

        depto[i] = criaDepartamento(depto[i].c1, depto[i].c2, depto[i].c3, depto[i].nome, depto[i].m1, depto[i].m2, depto[i].m3, depto[i].diretor);
    }

    ordenaPorMediaDepartamentos(depto, N);

    for (int i = 0; i < N; i++) {
        if (validaMediaDepartamento(depto[i].m1) && validaMediaDepartamento(depto[i].m2) && validaMediaDepartamento(depto[i].m3)) {
            imprimeAtributosDepartamento(depto[i]);
        }
    }

    return 0;
}
