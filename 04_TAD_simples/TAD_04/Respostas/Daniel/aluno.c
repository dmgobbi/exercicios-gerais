#include "aluno.h"
#include <stdio.h>
#include <string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3) {
  tAluno aluno; 
  strcpy(aluno.nome, nome);
  aluno.matricula = matricula;
  aluno.n1 = n1;
  aluno.n2 = n2;
  aluno.n3 = n3; 
  return aluno;
}

tAluno LeAluno() {
  tAluno aluno;
  scanf("%*[^a-z A-Z]");
  scanf("%s", aluno.nome);
  scanf("%d", &aluno.matricula);
  scanf("%d %d %d", &aluno.n1, &aluno.n2, &aluno.n3);
  return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
  return (aluno1.matricula > aluno2.matricula) ? -1 : ((aluno1.matricula < aluno2.matricula ? 1 : 0));
}

int CalculaMediaAluno(tAluno aluno) {
  return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int VerificaAprovacao(tAluno aluno) {
  return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno aluno) {
  printf("%s\n", aluno.nome);
}
