#include "aluno.h"
#include <stdio.h>

int main() {
  int qtdAlunos;

  scanf("%d", &qtdAlunos);
  tAluno aluno[qtdAlunos];

  for (int i = 0; i < qtdAlunos; i++) {
    aluno[i] = LeAluno();
  }
  
  for (int i = 0; i < qtdAlunos - 1; i++) {
    for (int j = 0; j < qtdAlunos - i - 1; j++) {
      if (ComparaMatricula(aluno[j], aluno[j + 1]) == 1) {
        tAluno temp = aluno[j];
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

  return 0;
}
