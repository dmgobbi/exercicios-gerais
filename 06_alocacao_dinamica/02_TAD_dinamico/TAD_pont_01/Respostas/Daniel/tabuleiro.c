#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

tTabuleiro* CriaTabuleiro() {
    tTabuleiro* tabuleiro = (tTabuleiro*) malloc(sizeof(tTabuleiro));
  
    if (tabuleiro == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(2);
    }
  
    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazio = '-';

    tabuleiro->posicoes = (char**) malloc(TAM_TABULEIRO * sizeof(char*));

    if (tabuleiro->posicoes == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(3);
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        // tabuleiro->posicoes[i] = (char*) malloc(TAM_TABULEIRO * sizeof(char));
        *(tabuleiro->posicoes + i) = (char*) malloc(TAM_TABULEIRO * sizeof(char));

        if (*(tabuleiro->posicoes + i) == NULL) {
            printf("Falha na alocacao de memoria\n");
            exit(4);
        }

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio;
            *(*(tabuleiro->posicoes + i) + j) = tabuleiro->pecaVazio;
        }
    }

    return tabuleiro;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        // free(tabuleiro->posicoes[i]);
        free(*(tabuleiro->posicoes + i));
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y) {
  switch (peca) {
  case 1:
    // tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    *(*(tabuleiro->posicoes + y) + x) = tabuleiro->peca1;
    break;
  case 2:
    // tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    *(*(tabuleiro->posicoes + y) + x) = tabuleiro->peca2;
    break;
  default:
    printf("[ERRO] Jogador invalido!\n");
  }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // if (tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio) {
            //     return 1;
            // }
            if (*(*(tabuleiro->posicoes + i) + j) == tabuleiro->pecaVazio) {
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca) {
    switch (peca) {
        case 1:
            // return tabuleiro->posicoes[y][x] == tabuleiro->peca1;
            return *(*(tabuleiro->posicoes + y) + x) == tabuleiro->peca1;
        case 2:
            // return tabuleiro->posicoes[y][x] == tabuleiro->peca2;
            return *(*(tabuleiro->posicoes + y) + x) == tabuleiro->peca2;
        default:
            printf("[ERRO] Jogador Invalido!\n");
    }
        return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y) {
    // return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
    return *(*(tabuleiro->posicoes + y) + x) == tabuleiro->pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (x >= 0 && x < TAM_TABULEIRO && 
            y >= 0 && y < TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (j == 0) printf("\t");
            // printf("%c", tabuleiro->posicoes[i][j]);
            printf("%c", *(*(tabuleiro->posicoes + i) + j));
        }
        printf("\n");
    }
}
