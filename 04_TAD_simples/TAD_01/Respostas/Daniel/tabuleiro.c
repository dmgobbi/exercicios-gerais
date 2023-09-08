#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro() {
    tTabuleiro tabuleiro;

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro.posicoes[i][j] = '-';
        }
    }

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    switch (peca) {
        case 1:
            tabuleiro.posicoes[x][y] = tabuleiro.peca1;
            break;
        case 2:
            tabuleiro.posicoes[x][y] = tabuleiro.peca2;
            break;
        default: 
            printf("ERRO: Peca invalida.\n");
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio;
            return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    switch (peca) {
        case 1: 
            return tabuleiro.posicoes[x][y] == tabuleiro.peca1;
        case 2:
            return tabuleiro.posicoes[x][y] == tabuleiro.peca2;
        default: 
            printf("ERRO: Peca invalida.\n");
            return -1;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y) { 
    return (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
           printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}
