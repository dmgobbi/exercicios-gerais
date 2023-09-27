#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

tBiblioteca inicializarBiblioteca() {
    tBiblioteca biblioteca;
    tLivros livro[MAX_LIVROS];
    biblioteca.tamanho = 0;
    
    for (int i = 0; i < MAX_LIVROS; i++) {
        strcpy(livro[i].titulo, "");
        strcpy(livro[i].autor, "");
        livro[i].anoPublicacao = 0;
        biblioteca.livros[i] = livro[i];     
    }

    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    int qtdLivros = biblioteca.tamanho;
    
    if (qtdLivros < MAX_LIVROS) {
        biblioteca.livros[qtdLivros++] = livro;
        biblioteca.tamanho = qtdLivros;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo) {
    tLivros livro;
    int livroEncontrado = 0;

    for (int i = 0; i < biblioteca.tamanho; i++) {
        livro = biblioteca.livros[i];
        if (!verificaTituloDoLivroNaBiblioteca(livro, titulo)) {
            livroEncontrado = 1;

            for (int j = i; j < biblioteca.tamanho - 1; j++) {
                biblioteca.livros[j] = biblioteca.livros[j + 1];
            }

            biblioteca.tamanho--;

            printf("Livro removido com sucesso!\n");
            break;
        }
    }

    if (!livroEncontrado) {
        printf("Livro nao encontrado na biblioteca.\n");
    }

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo) {
    return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    if (biblioteca.tamanho > 0) {
        printf("\nLista de Livros na Biblioteca:\n");
        for (int i = 0; i < biblioteca.tamanho; i++) {
            imprimeLivro(biblioteca.livros[i]);
        }
    } else {
        printf("A biblioteca esta vazia!\n");
    }
}
