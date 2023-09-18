#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro() {
  tTabuleiro tabuleiro;
  tabuleiro.peca1 = 'X';
  tabuleiro.peca2 = '0';
  tabuleiro.pecaVazio = '-';

  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
    }
  }
  return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
  switch (peca) {
  case 1:
    tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    break;
  case 2:
    tabuleiro.posicoes[y][x] = tabuleiro.peca2;
    break;
  default:
    printf("[ERRO] Jogador invalido!\n");
  }
  return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio) {
        return 1;
      }
    }
  }
  return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y,
                                    int peca) {
  switch (peca) {
  case 1:
    return tabuleiro.posicoes[y][x] == tabuleiro.peca1;
  case 2:
    return tabuleiro.posicoes[y][x] == tabuleiro.peca2;
  default:
    printf("[ERRO] Jogador Invalido!\n");
    return 0;
  }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
 return tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
  return (x >= 0 && x < TAM_TABULEIRO && 
          y >= 0 && y < TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (j == 0) {
        printf("\t");
      }
      printf("%c", tabuleiro.posicoes[i][j]);
    }
    printf("\n");
  }
}
