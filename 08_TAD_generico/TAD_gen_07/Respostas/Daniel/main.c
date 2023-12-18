#include "imagem.h"
#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int numIntervals;
    scanf(" %d\n", &numIntervals);
    Imagem *img = LerImagem();
    Histograma *hist = CalcularHistograma(img, numIntervals);
    MostrarHistograma(hist);
    DestruirImagem(img);
    DestruirHistograma(hist);
    return EXIT_SUCCESS;
}