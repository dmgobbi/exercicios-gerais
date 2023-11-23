#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char operacao;
    tBanco *banco = CriaBanco();
    bool flag = true;

    while (flag) {

        scanf("%c", &operacao);

        switch (operacao) {
            case 'F':
                DestroiBanco(banco);
                break;
            case 'S':
                SaqueContaBanco(banco);
                break;
            case 'D':
                DepositoContaBanco(banco);
                break;
            case 'T':
                TransferenciaContaBanco(banco);
                break;
            case 'A':
                AbreContaBanco(banco);
                break;
            case 'R':
                ImprimeRelatorioBanco(banco);
                flag = false;
                break;
            default:
                printf("Operacao invalida!\n");
                break;
        } 
    }
    DestroiBanco(banco);
    return 0;
}
