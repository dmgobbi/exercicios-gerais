#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

struct tImagem {
    int altura;
    int largura;
    Tipo tipo;
    void *dados;
};

int ObterAltura(Imagem *img) {
    if (img->dados == NULL) {
        printf("Erro: altura da imagem nao foi definida\n");
        return -1;
    }
    return img->altura;
}

int ObterLargura(Imagem *img) {
    if (img->dados == NULL) {
        printf("Erro: largura da imagem nao foi definida\n");
        return -1;
    }
    return img->largura;
}

Tipo ObterTipoImagem(Imagem *img) {
    if (img->dados == NULL) {
        printf("Erro: tipo da imagem nao foi definido\n");
        return -1;
    }
    return img->tipo;
}

void *ObterDadosImagem(Imagem *img) {
    if (img->dados == NULL) {
        printf("Erro: dados da imagem nao foram alocados\n");
        return NULL;
    }
    return img->dados;
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo) {
    Imagem *img = (Imagem *) malloc(sizeof(Imagem));
    if (img == NULL) {
        printf("Erro ao alocar memoria para a imagem\n");
        exit(EXIT_FAILURE);
    }
    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;
    img->dados = NULL;
    return img;
}

Imagem *LerImagem() {
    int altura, largura, temp;
    Tipo dados;
    if (scanf("%d %d %d\n", &altura, &largura, &temp) != 3) {
        printf("Erro ao ler dados da imagem\n");
        exit(EXIT_FAILURE);
    }

    dados = (Tipo) temp;
    Imagem *img = CriarImagem(altura, largura, dados);

    int tamanho = altura * largura;
    switch (dados) {
        case FLOAT:
            img->dados = malloc(sizeof(float) * tamanho);
            if (img->dados == NULL) {
                printf("Erro ao alocar memoria para os dados da imagem\n");
                DestruirImagem(img);
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < tamanho; i++) { 
                if (scanf(" %f", ((float *)img->dados) + i) != 1) {
                    printf("Erro ao ler pixel da imagem\n");
                    DestruirImagem(img);
                    exit(EXIT_FAILURE);
                }
            }
            break;
        case INT:
            img->dados = malloc(sizeof(int) * tamanho);
            if (img->dados == NULL) {
                printf("Erro ao alocar memoria para os dados da imagem\n");
                DestruirImagem(img);
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < tamanho; i++) {
                if (scanf(" %d", ((int *)img->dados) + i) != 1) {
                    printf("Erro ao ler pixel da imagem\n");
                    DestruirImagem(img);
                    exit(EXIT_FAILURE);
                }
            }            
            break;
        default:
            printf("Erro: tipo de dados nao suportado\n");
            DestruirImagem(img);
            exit(EXIT_FAILURE);
    }
    return img;
}

void DestruirImagem(Imagem *img) {
    if (img->dados != NULL) {
        free(img->dados);
    } else {
        printf("Erro: Esta tentando destruir uma imagem que nao foi criada\n");
        exit(EXIT_FAILURE);
    }
    free(img);
}
