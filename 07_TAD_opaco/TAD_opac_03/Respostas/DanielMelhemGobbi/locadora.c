#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 1000

struct Locadora {
    tFilme** filme; 
    int numFilmes; 
    int lucro; 
};

tLocadora* CriarLocadora () {
    tLocadora* locadora = (tLocadora*) malloc(sizeof(tLocadora));
    
    if (locadora == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }

    locadora->filme = (tFilme**) malloc(MAX_FILMES * sizeof(tFilme*));

    if (locadora->filme == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }
    
    for (int i = 0; i < MAX_FILMES; i++) {
        locadora->filme[i] = NULL;
    }

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

void DestruirLocadora (tLocadora* locadora) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora (tLocadora* locadora, tFilme* filme) {
    int qtdAtual = locadora->numFilmes;
    int jaCadastrado = 0;

    for (int i = 0; i < qtdAtual; i++) {
        if (VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {
            printf("Filme ja cadastrado no estoque\n");
            jaCadastrado = 1;
            break;
        }
    }

    if (!jaCadastrado) {
        locadora->filme[qtdAtual] = filme;
        locadora->numFilmes++;
        printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
        ImprimirNomeFilme(locadora->filme[qtdAtual]);
        printf("\n");
    }
}

void LerCadastroLocadora (tLocadora* locadora) {
    tFilme* filme = CriarFilme();
    int codigo;
    
    while (1) {
        if (scanf("%d,", &codigo) != 1) break;      
        LeFilme(filme, codigo);
        CadastrarFilmeLocadora(locadora, filme);
    }
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    int qtdAlugados = 0;
    int custo = 0;
    
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (!VerificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        } else {
            for (int j = 0; j < locadora->numFilmes; j++) {
                if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    tFilme* filme = locadora->filme[j];
                    int codigo = ObterCodigoFilme(filme);
                    int qtdEstoque = ObterQtdEstoqueFilme(filme);

                    if (!qtdEstoque) {
                        printf("Filme %d - ", codigo);
                        ImprimirNomeFilme(filme);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    } else {
                        AlugarFilme(filme);
                        custo += ObterValorFilme(filme);
                        qtdAlugados++;
                    }
                    break;
                }
            }
        }
    }

    if (qtdAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, custo);
    } 

    printf("\n");
}

void LerAluguelLocadora (tLocadora* locadora) {
    int codigo[MAX_FILMES];
    int qtdCodigos = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &codigo[i++]) == 1) {
            qtdCodigos++;
        } else {
            break;
        }
    }

    AlugarFilmesLocadora(locadora, codigo, qtdCodigos);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (!VerificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        } else {
            for (int j = 0; j < locadora->numFilmes; j++) {
                if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    tFilme* filme = locadora->filme[j];
                    int codigo = ObterCodigoFilme(filme);
                    int qtdAlugada = ObterQtdAlugadaFilme(filme);
                    int valor = ObterValorFilme(filme);
                  
                    if (!qtdAlugada) {
                        printf("Nao e possivel devolver o filme %d - ", codigo);
                        ImprimirNomeFilme(filme);
                        printf(".\n");
                    } else {
                        DevolverFilme(filme);
                        locadora->lucro += valor;
                        printf("Filme %d - ", codigo);
                        ImprimirNomeFilme(filme);
                        printf(" Devolvido!\n");
                    }
                    break;
                }
            }
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora) {
    int codigo[MAX_FILMES];
    int qtdCodigos = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &codigo[i++]) == 1) {
            qtdCodigos++;
        } else {
            break;
        }
    }

    DevolverFilmesLocadora(locadora, codigo, qtdCodigos);
}

void OrdenarFilmesLocadora (tLocadora* locadora) {
    for (int i = 0; i < locadora->numFilmes - 1; i++) {
        for (int j = i + 1; j < locadora->numFilmes; j++) {
            if (CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) > 0) {
                tFilme* aux = locadora->filme[i];
                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = aux;
            }
        }
    }
}

void ConsultarEstoqueLocadora (tLocadora* locadora) {
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora->numFilmes; i++) {
        tFilme* filme = locadora->filme[i];
        int codigo = ObterCodigoFilme(filme);
        int qtdEstoque = ObterQtdEstoqueFilme(filme);

        printf("%d - ", codigo);
        ImprimirNomeFilme(filme);
        printf(" Fitas em estoque: %d\n", qtdEstoque);
    }
    printf("\n");
}

void ConsultarLucroLocadora (tLocadora* locadora) {
    if (locadora->lucro) {
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}
