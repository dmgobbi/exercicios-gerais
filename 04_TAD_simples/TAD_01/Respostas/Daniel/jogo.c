#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

tJogo CriaJogo() {
    tJogo jogo;
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();
    return jogo;
}

void ComecaJogo(tJogo jogo) {
  while (1) {
    jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
    ImprimeTabuleiro(jogo.tabuleiro);
    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
      printf("JOGADOR 1 Venceu!\n");
      break;
    }

    if (AcabouJogo(jogo)) {
      printf("Sem vencedor!\n");
      break;
    }

    jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
    ImprimeTabuleiro(jogo.tabuleiro);
    if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
      printf("JOGADOR 2 Venceu!\n");
      break;
    }    

    if (AcabouJogo(jogo)) {
      printf("Sem vencedor!\n");
      break;
    }
  }
}

int AcabouJogo(tJogo jogo) {
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo() {
    char opcao = '\0';
    while (1) {
      printf("Jogar novamente? (s,n)\n");

      scanf("%*[^sn]");
      if (scanf("%c", &opcao) == 1) {
        if (opcao == 's' || opcao == 'n') {
          break;
        } 
      }
      scanf("%*[^\n]");
    }
    return opcao == 's';
}
