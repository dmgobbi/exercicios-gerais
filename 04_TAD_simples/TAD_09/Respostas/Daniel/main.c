#include <stdio.h>
#include "empresa.h"

int main() {
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);
    tEmpresa empresa[qtdEmpresas];

    for (int i = 0; i < qtdEmpresas; i++) {
        empresa[i] = leEmpresa();
    }

    for (int i = 0; i < qtdEmpresas; i++) {
        imprimeEmpresa(empresa[i]);
    }

    return 0;
}
