#include <stdio.h>
#include "jogo.h"

int main() {
    while (1) {
        tJogo jogo = CriaJogo();
        ComecaJogo(jogo);
    }
    return 0;
}
