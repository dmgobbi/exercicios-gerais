#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int x, y, livre = 0, valida = 0;
    do {
      printf("Jogador %d\n", jogador.id);
      tJogada jogada = LeJogada();
      if (!FoiJogadaBemSucedida(jogada)) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("Formato invalido!\n");
        continue;
      }

      x = ObtemJogadaX(jogada);
      y = ObtemJogadaY(jogada);

      valida = EhPosicaoValidaTabuleiro(x, y);
      if (valida) {
        livre = EstaLivrePosicaoTabuleiro(tabuleiro, x, y);
        if (!livre) {
          printf("Posicao invalida (OCUPADA - [%d,%d] )!", x, y);
        }
      } else {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!", x, y);
      }
    } while (!livre || !valida);

    int peca = (jogador.id == ID_JOGADOR_1 ? PECA_1: PECA_2);
    printf("Jogada [%d,%d]!\n", x, y);
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
    return tabuleiro;
} 
  
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int vencedor = 0;

    // Checa horizontal
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        vencedor = 0;
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)) {
                vencedor++;
                
                if (vencedor == TAM_TABULEIRO) {
                    return 1;
                }
            }
        }
    }

    // Checa vertical
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        vencedor = 0;
        for(int i = 0; i < TAM_TABULEIRO; i++) {
            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)) {
                vencedor++;
                
                if (vencedor == TAM_TABULEIRO) {
                    return 1;
                }
            }
        }
    }

    // Chega diagonal
    vencedor = 0;
    for (int i = 0, j = 0; i < TAM_TABULEIRO; i++, j++) {
        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)) {
            vencedor++;
            
            if (vencedor == TAM_TABULEIRO) {
                return 1;
            }
        }
    }

    vencedor = 0;
    for (int i = 0, j = TAM_TABULEIRO - 1; i < TAM_TABULEIRO; i++, j--) {
        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)) {
            vencedor++;
            
            if (vencedor == TAM_TABULEIRO) {
                return 1;
            }
        }
    }

    return 0;
}
