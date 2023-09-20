#include "conta.h"
#include <stdio.h>

int main() {
    char cpf[15], nome[20];
    float valor;
    int contasCriadas = 0, id, numero, operacao, qtdContas;

    scanf("%d", &qtdContas);
    tConta conta[qtdContas];

    while (1) {

        scanf("%d", &operacao);

        switch (operacao) {
            case 0:
                return 0;
            case 1:
                scanf("%d %f", &id, &valor);
                for (int i = 0; i < contasCriadas; i++) {
                    if (VerificaConta(conta[i], id)) {
                        conta[i] = SaqueConta(conta[i], valor);
                    }
                }
                break;
            case 2:
                scanf("%d %f", &id, &valor);
                for (int i = 0; i < contasCriadas; i++) {
                    if (VerificaConta(conta[i], id)) {
                        conta[i] = DepositoConta(conta[i], valor);
                    }
                }
                break;
            case 3:
                scanf("%s %s %d", nome, cpf, &numero);
                if (contasCriadas < qtdContas) {
                    conta[contasCriadas++] = CriaConta(numero, CriaUsuario(nome, cpf));
                }
                break;
            case 4:
                printf("===| Imprimindo Relatorio |===\n");
                for (int i = 0; i < contasCriadas; i++) {
                    ImprimeConta(conta[i]);
                    printf("\n");
                }
                break;
            default:
                printf("Operacao invalida!\n");
                break;
        } 
    }
    return 0;
}
