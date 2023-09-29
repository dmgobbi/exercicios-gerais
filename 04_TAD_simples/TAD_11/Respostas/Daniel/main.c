#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

int main() {
    tVendedor vendedor;
    int idLoja, operacao = -1, qtdLojas, qtdLojasAbertas = 0;
    float aluguel, valorVenda, prct_comissao, salario;
    char nome[50];

    scanf("%d", &qtdLojas);
    tLoja loja[qtdLojas];

    while (operacao != 0) {
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 0:
            break;
        case 1:
            scanf("%d %f", &idLoja, &aluguel);
            loja[qtdLojasAbertas++] = AbreLoja(idLoja, aluguel);
            break;
        case 2:
            scanf("%s %f %f", nome, &salario, &prct_comissao);
            vendedor = RegistraVendedor(nome, salario, prct_comissao);
            scanf("%d", &idLoja);
            for (int i = 0; i < qtdLojasAbertas; i++) {
                if (VerificaIdLoja(loja[i], idLoja)) {
                    loja[i] = ContrataVendedor(loja[i], vendedor);
                }
            }
            break;
        case 3:
            scanf("%d %s %f", &idLoja, nome, &valorVenda);
            for (int i = 0; i < qtdLojas; i++) {
                if (VerificaIdLoja(loja[i], idLoja)) {
                    loja[i] = RegistraVenda(loja[i], nome, valorVenda);
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < qtdLojasAbertas; i++) {
                loja[i] = CalculaLucro(loja[i]);
                ImprimeRelatorioLoja(loja[i]);
            }
            break;
        default:
            printf("Operacao invalida!\n");
            break;
        }
    }
    return 0;
}





