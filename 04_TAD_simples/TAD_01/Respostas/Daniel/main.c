#include <stdio.h>
#include "jogo.h"

int main() {
    do {
        tJogo jogo = CriaJogo();
        ComecaJogo(jogo);
    } while (ContinuaJogo());
    
    return 0;
}
