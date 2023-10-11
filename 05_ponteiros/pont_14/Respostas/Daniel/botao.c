#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "botao.h"

void SetarTexto(Botao *b, char *novoTexto) {
    if (strlen(novoTexto) > MAX_TAM_TEXTO) {
        printf("Erro: Novo texto eh maior que o tamanho maximo permitido!\n");
        exit(3);
    }

    strcpy(b->texto, novoTexto);
}

void SetarTamFonte(Botao *b, int novoTamFonte) {
    if (novoTamFonte <= 0) {
        printf("Erro: Novo tamanho da fonte eh menor que o tamanho minimo permitido!\n");
        exit(4);
    }

    b->tamFonte = novoTamFonte;
}

void SetarCor(Botao *b, char *novaCor) {
    if (strlen(novaCor) >= 7) {
        printf("Erro: Nova cor eh maior que o tamanho maximo permitido!\n");
        exit(5);
    }

    strcpy(b->corHex, novaCor);
}

void SetarTipo(Botao *b, int novoTipo) {
    if (!(novoTipo == CLICK || novoTipo == LONGO_CLICK || novoTipo == HOVER)) {
        printf("Erro: Novo tipo invalido!\n");
        exit(6);
    }

    b->tipo = novoTipo;
}

Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)) {
    Botao b;
    SetarTexto(&b, texto);
    SetarTamFonte(&b, tamFonte);
    SetarCor(&b, cor);
    SetarTipo(&b, tipo);
    b.executa = executa;
    return b;
}

void ExecutaBotao(Botao b) {
    if (b.tipo == CLICK) {
        printf("- Executando o botao com evento de click\n");
    } else if (b.tipo == LONGO_CLICK) {
        printf("- Executando o botao com evento de longo click\n");
    } else {
        printf("Erro: Tipo invalido!\n");
        exit(7);
    }

    b.executa();
}

void DesenhaBotao(Botao b, int idx) {
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}
