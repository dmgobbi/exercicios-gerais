#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct funcionario {
    int id;
    float salario;
};

tFuncionario* CriaFuncionario() {
    tFuncionario* f = (tFuncionario*) malloc(sizeof(tFuncionario));
    f->id = -1;
    f->salario = -1;
    return f;
}

void ApagaFuncionario(tFuncionario* f) {
    free(f);
}

void LeFuncionario(tFuncionario* f){
    int id;
    float salario;
    scanf("%d %f", &id, &salario);
    f->id = id;
    f->salario = salario;
}

int GetIdFuncionario(tFuncionario* f) {
    return f->id;
}

void ImprimeFuncionario(tFuncionario* f) {
    printf("- Funcionario %d: RS %.2f\n", f->id, f->salario);
}
