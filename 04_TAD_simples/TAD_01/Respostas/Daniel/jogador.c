#include "jogador.h"
//#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = (idJogador == 1 || idJogador == 2) ? idJogador : -1;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    /* tJogada jogada;
    jogada = LeJogada();
    int x = ObtemJogadaX(jogada);
    int y = ObtemJogadaY(jogada); */

    if (EhPosicaoValidaTabuleiro(x, y) && EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
    }
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
