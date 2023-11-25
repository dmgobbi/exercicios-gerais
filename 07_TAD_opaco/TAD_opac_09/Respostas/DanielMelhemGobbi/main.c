#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main() {
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);

    tEmpresa** empresa = (tEmpresa**) malloc(qtdEmpresas * sizeof(tEmpresa*));

    for (int i = 0; i < qtdEmpresas; i++) {
        empresa[i] = CriaEmpresa();
        LeEmpresa(empresa[i]);
    }

    for (int i = 0; i < qtdEmpresas; i++) {
        ImprimeEmpresa(empresa[i]);
        printf("\n");
        ApagaEmpresa(empresa[i]);
    }

    free(empresa);

    return 0;
}
