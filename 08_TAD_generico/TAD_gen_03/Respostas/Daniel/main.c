#include "aluno.h"
#include "relatorio.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int qtdAlunos;
    scanf(" %d", &qtdAlunos);
    
    Vector* alunos = VectorConstruct();

    for (int i = 0; i < qtdAlunos; i++) {
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(alunos, aluno);
    }

    ImprimeRelatorio(alunos);
    VectorDestroy(alunos, DestroiAluno);

    return 0;
}
