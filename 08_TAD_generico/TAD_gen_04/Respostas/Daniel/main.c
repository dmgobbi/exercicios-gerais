#include "banco.h"
#include "agencia.h"
#include "conta.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int numAgencia;
    char operation;
    bool acabouContas;

    tBanco *banco = CriaBanco();
    tAgencia *agencia = NULL;
    tConta *conta = NULL;

    LeBanco(banco);

    acabouContas = false;
    while (!acabouContas) {
        scanf(" %c\n", &operation);
        if (operation == 'F') {
            acabouContas = true;
            break;
        }

        switch (operation) {
            case 'A':
                agencia = CriaAgencia();
                LeAgencia(agencia);
                AdicionaAgencia(banco, agencia);
                break;
            case 'C':
                conta = CriaConta();
                LeConta(conta);
                scanf(" %d\n", &numAgencia);
                InsereContaBanco(banco, numAgencia, conta);
                break;
            default:
                printf("Operacao invalida.\n");
                acabouContas = true;
                break;
        }
    }

    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    return EXIT_SUCCESS;
}
