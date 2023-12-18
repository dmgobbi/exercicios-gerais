#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

struct tHistograma {
    int* pixelCounts;
    int numIntervals; 
    int intervalSize; 
};

Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
    if (img == NULL) {
        printf("Erro: imagem nao foi alocada\n");
        exit(EXIT_FAILURE);
    }

    Histograma *hist = malloc(sizeof(Histograma));
    if (hist == NULL) {
        printf("Erro ao alocar memoria para o histograma\n");
        exit(EXIT_FAILURE);
    }
    hist->numIntervals = nIntervalos;
    hist->intervalSize = (256 + nIntervalos - 1) / nIntervalos;
    hist->pixelCounts = calloc(nIntervalos, sizeof(int));
    if (hist->pixelCounts == NULL) {
        printf("Erro ao alocar memoria para o histograma\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the histogram
    for (int i = 0; i < ObterAltura(img) * ObterLargura(img); i++) {
        int pixelValue;
        if (ObterTipoImagem(img) == FLOAT) {
            float *data = (float *)ObterDadosImagem(img);
            pixelValue = lroundf(data[i] * 255);            
        } else {
            int *data = (int *)ObterDadosImagem(img);
            pixelValue = data[i];
        }
        int intervalIndex = pixelValue / hist->intervalSize;
        intervalIndex = min(intervalIndex, nIntervalos - 1);
        hist->pixelCounts[intervalIndex]++;
    }


    return hist;
}

void MostrarHistograma(Histograma *h) {
    if (h->pixelCounts == NULL) {
        printf("Erro: dados do histograma nao foram alocados\n");
        return;
    }
    for (int i = 0; i < h->numIntervals; i++) {
        printf("[%d, %d): %d\n", i * h->intervalSize, (i + 1) * h->intervalSize, h->pixelCounts[i]);
    }
}

void DestruirHistograma(Histograma *h) {
    if (h->pixelCounts != NULL) {
        free(h->pixelCounts);
    } else {
        printf("Erro: dados do histograma nao foram alocados\n");
    }
    free(h);
}