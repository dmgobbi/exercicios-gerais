#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;
    loja.id = id;
    loja.totalVendedores = 0;
    loja.aluguel = aluguel;
    loja.lucro = 0;

    tVendedor vendedor[MAX_VENDEDORES];
    for (int i = 0; i < MAX_VENDEDORES; i++) {
        strcpy(vendedor[i].nome, "");
        vendedor[i].valor_vendido = 0;
        vendedor[i].salario = 0;
        vendedor[i].prct_comissao = 0;
        loja.vendedores[i] = vendedor[i];
    }

    return loja;
}

int VerificaIdLoja(tLoja loja, int id) {
    return loja.id == id;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    loja.vendedores[loja.totalVendedores++] = vendedor;
    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {
    for (int i = 0; i < loja.totalVendedores; i++) {
        if (VerificaNomeVendedor(loja.vendedores[i], nome)) {
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);   
            break; 
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja) {
    float receita = 0;
    float custo = 0;

    for (int i = 0; i < loja.totalVendedores; i++) {
        receita += GetTotalVendido(loja.vendedores[i]);
        custo += GetTotalRecebido(loja.vendedores[i]);
    }
    custo += loja.aluguel;
    loja.lucro = receita - custo;

    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    for (int i = 0; i < loja.totalVendedores; i++) {
        ImprimeRelatorioVendedor(loja.vendedores[i]);   
    }
}
