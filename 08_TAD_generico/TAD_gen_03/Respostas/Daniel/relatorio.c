#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void ImprimeRelatorio(Vector *alunos) {
    if (!alunos) {
        printf("Erro: vetor alunos eh NULL.\n");
        exit(EXIT_FAILURE);
    }

    int tamanho = VectorSize(alunos);
    float qAprovados = 0;
    float qMasculino = 0, qFeminino = 0, qOutros = 0;
    float totalNotas = 0;

    for (int i = 0; i < tamanho; i++) {
        tAluno* aluno = (tAluno*) VectorGet(alunos, i);
        totalNotas += GetNotaAluno(aluno);

        if (GetNotaAluno(aluno) >= 6) qAprovados++;

        if (GetGeneroAluno(aluno) == 'M') qMasculino++;
        else if (GetGeneroAluno(aluno) == 'F') qFeminino++;
        else qOutros++;
    }

    printf("Media das notas: %.2f\n",  totalNotas/(float) tamanho);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (qAprovados/tamanho)*100.0);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (qMasculino/tamanho)*100.0);
    printf("Feminino: %.2f%%\n", (qFeminino/tamanho)*100.0) ;
    printf("Outro: %.2f%%\n", (qOutros/tamanho)*100.0);
}