#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

struct Jogada {
    int x;
    int y;
    int sucesso;
};

tJogada* CriaJogada() {
    tJogada* jogada = (tJogada*) malloc(sizeof(tJogada));

    if (jogada == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }

    return jogada;
}

void DestroiJogada(tJogada* jogada) {
    free(jogada);
}

void LeJogada(tJogada* jogada) {
    printf("Digite uma posicao (x e y):\n");
    jogada->sucesso = scanf("%d %d", &jogada->x, &jogada->y) == 2;
}

int ObtemJogadaX(tJogada* jogada) {
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada) { 
    return jogada->sucesso;
}
