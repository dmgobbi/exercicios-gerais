#include "jogo.h"
#include <stdio.h>

tJogo CriaJogo() {
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    return jogo;
}

void ComecaJogo(tJogo jogo) {}

int AcabouJogo(tJogo jogo) {
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo() {
    char opcao;
    while (1) {
        printf("Jogar novamente? (s,n) ");
        scanf("%c", &opcao);
        if (opcao == 's' || opcao == 'n') {
            break;
        } 
    }
    return opcao == 's';
}
