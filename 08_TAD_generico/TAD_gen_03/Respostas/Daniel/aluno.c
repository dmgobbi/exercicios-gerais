#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 51

struct Aluno {
    char nome[MAX_NOME];
    char genero;
    float nota;
};

tAluno *CriaAluno() {
    tAluno *aluno = (tAluno *) calloc(1, sizeof(tAluno));
    if (!aluno) {
        printf("Erro na alocacao de memoria do aluno.\n");
        exit(EXIT_FAILURE);
    }
    return aluno;
}

void DestroiAluno(data_type aluno) {
    tAluno *alunoPtr = (tAluno *) aluno;
    if (!alunoPtr) {
        printf("Erro na leitura do aluno.\n");
        exit(EXIT_FAILURE);
    }
    free(alunoPtr);
}

void LeAluno(tAluno *aluno) {
    if (!aluno) {
        printf("Erro na leitura do aluno.\n");
        exit(EXIT_FAILURE);
    }
    scanf(" %[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno) {
    if (!aluno) {
        printf("Erro na leitura do aluno.\n");
        exit(EXIT_FAILURE);
    }
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno) {
    if (!aluno) {
        printf("Erro na leitura do aluno.\n");
        exit(EXIT_FAILURE);
    }
    return aluno->nota;
}
