#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

tLivros lerLivro() {
    tLivros livro;
    char titulo[100];
    char autor[50];
    int anoPublicacao;

    scanf("%99[^\n]\n", titulo);
    scanf("%49[^\n]\n", autor);
    scanf("%d\n", &anoPublicacao);

    strcpy(livro.titulo, titulo);
    strcpy(livro.autor, autor);
    livro.anoPublicacao = anoPublicacao;

    return livro;
}

void imprimeLivro(tLivros livro) {
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
    printf("\n");
}
