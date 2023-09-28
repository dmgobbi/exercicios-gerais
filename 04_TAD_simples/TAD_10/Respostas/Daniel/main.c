#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    int N;

    scanf("%d", &N);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");

    tLivros livro;
    tBiblioteca biblioteca;
    biblioteca = inicializarBiblioteca();

    int operacao;
    char titulo[100];
    
    while (N > 0) {
        
        scanf("%d", &operacao);

        switch (operacao) {
            case 1:
                livro = lerLivro();
                biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
                break;
            case 2:    
                scanf("%*c");
                scanf("%99[^\n]\n", titulo);
                biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);      
                break;
            case 3:
                listarLivrosDaBiblioteca(biblioteca);
                break;
            default:
                printf("Operacao invalida!\n");
                return 1;
        }
        N--;
    } 
    return 0;
}
