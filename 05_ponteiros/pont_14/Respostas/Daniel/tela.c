#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

Tela CriarTela(int altura, int largura) {
    Tela t;
    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b) {
    if (t->qntBotoes < MAX_BOTOES) {
        t->botoes[t->qntBotoes++] = b;
    }
}

void DesenhaTela(Tela t) {
    if (t.qntBotoes == 0) {
        return;
    }

    printf("##################\n");
    for (int i = 0; i < t.qntBotoes; ++i) {
        DesenhaBotao(t.botoes[i], i);
        printf("\n");
    }
    printf("##################\n");
}

void OuvidorEventosTela(Tela t) {
    int acao;
    printf("- Escolha sua acao: ");

    if (scanf("%d", &acao) != 1) {
        printf("Erro: Entrada invalida!\n");
        exit(1);
    }

    if (acao < 0 || acao >= MAX_BOTOES) {
        printf("Erro: Acao invalida!\n");
        exit(2);
    }

    Botao b = t.botoes[acao];
    ExecutaBotao(b);
}
