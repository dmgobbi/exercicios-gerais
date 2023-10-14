// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "locadora.h"

// tLocadora criarLocadora () {
//     tLocadora locadora;
//     locadora.numFilmes = 0;
//     locadora.lucro = 0;

//     for (int i = 0; i < MAX_FILMES; i++) {
//         locadora.filme[i] = criarFilme("", 0, 0, 0);
//     }

//     return locadora;
// }

// int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
//     for (int i = 0; i < locadora.numFilmes; i++) {
//         if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
//             return 1;
//         }
//     }
//     return 0;
// }

// tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme) {
//     int qtdAtual = locadora.numFilmes;
//     int jaCadastrado = 0;

//     for (int i = 0; i < qtdAtual; i++) {
//         if (verificarFilmeCadastrado(locadora, filme.codigo)) {
//             printf("Filme ja cadastrado no estoque\n");
//             jaCadastrado = 1;
//             break;
//         }
//     }

//     if (!jaCadastrado) {
//         locadora.filme[qtdAtual] = criarFilme(filme.nome, filme.codigo, filme.valor, filme.qtdEstoque); 
//         locadora.numFilmes++;
//         printf("Filme cadastrado %d - ", filme.codigo);
//         imprimirNomeFilme(locadora.filme[qtdAtual]);
//         printf("\n");
//     }

//     return locadora;
// }

// tLocadora lerCadastroLocadora (tLocadora locadora) {
//     tFilme filme;
//     int codigo, valor, quantidade;
//     char nome[MAX_CARACTERES];
    
//     while (1) {
//         if (scanf("%d,%[^,],%d,%d", &codigo, nome, &valor, &quantidade) != 4) {
//             break;
//         }

//         filme = criarFilme(nome, codigo, valor, quantidade);
//         locadora = cadastrarFilmeLocadora(locadora, filme);
//     }
//     return locadora;
// }

// tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
//     int qtdAlugados = 0;
//     int custo = 0;
    
//     for (int i = 0; i < quantidadeCodigos; i++) {
//         if (!verificarFilmeCadastrado(locadora, codigos[i])) {
//             printf("Filme %d nao cadastrado.\n", codigos[i]);
//         } else {
//             for (int j = 0; j < locadora.numFilmes; j++) {
//                 if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
//                     tFilme filme = locadora.filme[j];
//                     int codigo = obterCodigoFilme(filme);
//                     int qtdEstoque = obterQtdEstoqueFilme(filme);

//                     if (!qtdEstoque) {
//                         printf("Filme %d - ", codigo);
//                         imprimirNomeFilme(filme);
//                         printf(" nao disponivel no estoque. Volte mais tarde.\n");
//                     } else {
//                         locadora.filme[j] = alugarFilme(filme);
//                         custo += obterValorFilme(filme);
//                         qtdAlugados++;
//                     }
//                     break;
//                 }
//             }
//         }
//     }

//     if (qtdAlugados > 0) {
//         printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, custo);
//     } 

//     printf("\n");
//     return locadora;
// }

// tLocadora lerAluguelLocadora (tLocadora locadora) {
//     int codigo[MAX_FILMES];
//     int qtdCodigos = 0;
//     int i = 0;

//     while (1) {
//         if (scanf("%d", &codigo[i++]) == 1) {
//             qtdCodigos++;
//         } else {
//             break;
//         }
//     }

//     locadora = alugarFilmesLocadora(locadora, codigo, qtdCodigos);
//     return locadora;
// }

// tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
//     for (int i = 0; i < quantidadeCodigos; i++) {
//         if (!verificarFilmeCadastrado(locadora, codigos[i])) {
//             printf("Filme %d nao cadastrado.\n", codigos[i]);
//         } else {
//             for (int j = 0; j < locadora.numFilmes; j++) {
//                 if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
//                     tFilme filme = locadora.filme[j];
//                     int codigo = obterCodigoFilme(filme);
//                     int qtdAlugada = obterQtdAlugadaFilme(filme);
//                     int valor = obterValorFilme(filme);

//                     if (!qtdAlugada) {
//                         printf("Nao e possivel devolver o filme %d - ", codigo);
//                         imprimirNomeFilme(filme);
//                         printf(".\n");
//                     } else {
//                         locadora.filme[j] = devolverFilme(filme);
//                         locadora.lucro += valor;
//                         printf("Filme %d - ", codigo);
//                         imprimirNomeFilme(filme);
//                         printf(" Devolvido!\n");
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     return locadora;
// }

// tLocadora lerDevolucaoLocadora (tLocadora locadora) {
//     int codigo[MAX_FILMES];
//     int qtdCodigos = 0;
//     int i = 0;

//     while (1) {
//         if (scanf("%d", &codigo[i++]) == 1) {
//             qtdCodigos++;
//         } else {
//             break;
//         }
//     }

//     locadora = devolverFilmesLocadora(locadora, codigo, qtdCodigos);
//     return locadora;
// }

// tLocadora ordenarFilmesLocadora (tLocadora locadora) {
//     for (int i = 0; i < locadora.numFilmes - 1; i++) {
//         for (int j = i + 1; j < locadora.numFilmes; j++) {
//             if (compararNomesFilmes(locadora.filme[i], locadora.filme[j]) > 0) {
//                 tFilme aux = locadora.filme[i];
//                 locadora.filme[i] = locadora.filme[j];
//                 locadora.filme[j] = aux;
//             }
//         }
//     }
//     return locadora;
// }

// void consultarEstoqueLocadora (tLocadora locadora) {
//     printf("~ESTOQUE~\n");
//     for (int i = 0; i < locadora.numFilmes; i++) {
//         tFilme filme = locadora.filme[i];
//         int codigo = obterCodigoFilme(filme);
//         int qtdEstoque = obterQtdEstoqueFilme(filme);

//         printf("%d - ", codigo);
//         imprimirNomeFilme(filme);
//         printf(" Fitas em estoque: %d\n", qtdEstoque);
//     }
//     printf("\n");
// }

// void consultarLucroLocadora (tLocadora locadora) {
//     if (locadora.lucro) {
//         printf("Lucro total R$%d\n", locadora.lucro);
//     }
// }
