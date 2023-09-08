#include "jogada.h"
#include <stdio.h>

tJogada LeJogada() {
    tJogada jogada;
    jogada.sucesso = scanf("%d %d", &jogada.x, &jogada.y) == 2;
    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) { 
    return jogada.sucesso;
}
