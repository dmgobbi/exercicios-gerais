#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

tLocadora criarLocadora () {
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;

    for (int i = 0; i < MAX_FILMES; i++) {
        locadora.filme[i] = criarFilme("", 0, 0, 0);
    }

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    for (int i = 0; i < locadora.numFilmes; i++) {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade) {
    int qtdAtual = locadora.numFilmes;

    for (int i = 0; i < qtdAtual; i++) {
        if (verificarFilmeCadastrado(locadora, codigo)) {
            printf("Filme ja cadastrado no estoque\n");
            return locadora;
        }
    }

    locadora.filme[qtdAtual] = criarFilme(nome, codigo, valor, quantidade); 
    locadora.numFilmes++;
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora) {
    tFilme filme;

    while (1) {
        filme = lerFilme();
        if (filme.codigo != -1) {
            locadora = cadastrarFilmeLocadora(locadora, filme.nome, filme.codigo, filme.valor, filme.qtdEstoque);
        } else {
            scanf("%*[^#]#");
            break;
        }

    }
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (!verificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado\n", codigos[i]);
        } else {
            for (int j = 0; j < locadora.numFilmes; j++) {
                if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                    tFilme filme = locadora.filme[j];
                    int codigo = obterCodigoFilme(filme);
                    int qtdEstoque = obterQtdEstoqueFilme(filme);

                    if (qtdEstoque == 0) {
                        printf("Filme %d - ", codigo);
                        imprimirNomeFilme(filme);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    } else {
                        locadora.filme[j] = alugarFilme(filme);
                        locadora.lucro += obterValorFilme(filme);
                    }
                    break;
                }
            }
        }
    }
    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora) {
    int codigo[MAX_FILMES];
    int qtdCodigos = 0;
    int i = 0;

    while (1) {
        if (locadora.numFilmes <= 0) {
            printf("Estoque vazio\n");
            scanf("%*[^#]#");
            break;
        }

        if (scanf("%d", &codigo[i++]) == 1) {
            qtdCodigos++;
        } else {
            scanf("%*[^#]#");
            break;
        }
    }

    locadora = alugarFilmesLocadora(locadora, codigo, qtdCodigos);
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (!verificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado\n", codigos[i]);
        } else {
            for (int j = 0; j < locadora.numFilmes; j++) {
                if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                    tFilme filme = locadora.filme[j];
                    int codigo = obterCodigoFilme(filme);
                    int qtdEstoque = obterQtdEstoqueFilme(filme);

                    if (qtdEstoque == MAX_FILMES) {
                        printf("Nao e possivel devolver o filme %d - ", codigo);
                        imprimirNomeFilme(filme);
                        printf("\n");
                    } else {
                        locadora.filme[j] = devolverFilme(filme);
                    }
                    break;
                }
            }
        }
    }
    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora) {
    int codigo[MAX_FILMES];
    int qtdCodigos = 0;
    int i = 0;

    while (1) {
        if (locadora.numFilmes >= MAX_FILMES) {
            printf("Estoque cheio\n");
            scanf("%*[^#]#");
            break;
        }

        if (scanf("%d", &codigo[i++]) == 1) {
            qtdCodigos++;
        } else {
            scanf("%*[^#]#");
            break;
        }
    }

    locadora = devolverFilmesLocadora(locadora, codigo, qtdCodigos);
    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora) {
    for (int i = 0; i < locadora.numFilmes - 1; i++) {
        for (int j = i + 1; j < locadora.numFilmes; j++) {
            if (compararNomesFilmes(locadora.filme[i], locadora.filme[j]) > 0) {
                tFilme aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }
        }
    }
    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora) {
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora.numFilmes; i++) {
        tFilme filme = locadora.filme[i];
        int codigo = obterCodigoFilme(filme);
        int qtdEstoque = obterQtdEstoqueFilme(filme);

        printf("%d - ", codigo);
        imprimirNomeFilme(filme);
        printf(" em estoque: %d\n", qtdEstoque);
    }
}

void consultarLucroLocadora (tLocadora locadora) {
    printf("Lucro total R$%d\n", locadora.lucro);
}
