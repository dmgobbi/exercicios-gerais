#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_STRING 50

struct Aluno {
    char* nome; /**< Ponteiro para nome do aluno, que será alocado dinamicamente*/
    int matricula; /**< Matrícula do aluno */
    int n1, n2, n3; /**< Notas das avaliações */
};

tAluno* CriaAluno() {
  tAluno *aluno = (tAluno*) malloc(sizeof(tAluno));

  if (aluno == NULL) {
    printf("Falha na alocacao de memoria\n");
    exit(1);
  }

  aluno->nome = (char*) malloc(MAX_STRING * sizeof(char));

  if (aluno->nome == NULL) {
    printf("Falha na alocacao de memoria\n");
    exit(1);
  }

  aluno->matricula = -1;
  aluno->n1 = -1;
  aluno->n2 = -1;
  aluno->n3 = -1;

  return aluno;
}

void ApagaAluno(tAluno *aluno) {
  free(aluno->nome);
  free(aluno);
}

void LeAluno(tAluno *aluno) {
  char nome[MAX_STRING];
  int matricula, n1, n2, n3;

  scanf("%*[^a-z A-Z]");
  scanf("%s", nome);
  scanf("%d", &matricula);
  scanf("%d %d %d", &n1, &n2, &n3);
  
  strcpy(aluno->nome, nome);
  aluno->matricula = matricula;
  aluno->n1 = n1;
  aluno->n2 = n2;
  aluno->n3 = n3;
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
  return (aluno1->matricula > aluno2->matricula) ? 1 : ((aluno1->matricula < aluno2->matricula ? -1 : 0));
}

int CalculaMediaAluno(tAluno* aluno) {
  return (aluno->n1 + aluno->n2 + aluno->n3) / 3;
}

int VerificaAprovacao(tAluno* aluno) {
  return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno* aluno) {
  printf("%s\n", aluno->nome);
}
