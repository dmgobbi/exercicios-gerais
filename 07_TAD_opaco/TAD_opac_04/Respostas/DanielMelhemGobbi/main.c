#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main() {
  int qtdAlunos;
  scanf("%d", &qtdAlunos);

  tAluno **aluno = (tAluno**) malloc(qtdAlunos * sizeof(tAluno*));
  
  if (aluno == NULL) {
    printf("Falha na alocacao de memoria\n");
    exit(1);
  }

  for (int i = 0; i < qtdAlunos; i++) {
    aluno[i] = CriaAluno();
    LeAluno(aluno[i]);
  }

  for (int i = 0; i < qtdAlunos - 1; i++) {
    for (int j = 0; j < qtdAlunos - i - 1; j++) {
      if (ComparaMatricula(aluno[j], aluno[j + 1]) == 1) {
        tAluno **temp = aluno[j];
        aluno[j] = aluno[j + 1];
        aluno[j + 1] = temp;
      }
    } 
  }

  for (int i = 0; i < qtdAlunos; i++) {
    if (VerificaAprovacao(aluno[i])) {
      ImprimeAluno(aluno[i]);
    }
  }

  for (int i = 0; i < qtdAlunos; i++) {
    ApagaAluno(aluno[i]);
  }
  free(aluno);

  return 0;
}
