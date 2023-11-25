#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

struct empresa {
    int id;
    tFuncionario** funcionarios;
    int qtdFuncionarios;
};

tEmpresa* CriaEmpresa() {
    tEmpresa* e = (tEmpresa*) malloc(sizeof(tEmpresa));
    if (e == NULL) {
        printf("Erro ao alocar empresa\n");
        exit(EXIT_FAILURE);
    }
    e->id = -1;
    e->funcionarios = NULL;
    e->qtdFuncionarios = -1;
    return e;
} 

void LeEmpresa(tEmpresa* e) {
    int id, qtdFuncionarios;

    if (scanf("%d %d", &id, &qtdFuncionarios) != 2) {
        printf("Erro ao ler empresa\n");
        exit(EXIT_FAILURE);
    }

    e->id = id;
    e->qtdFuncionarios = 0;

    for (int i = 0; i < qtdFuncionarios; i++) {
        tFuncionario* f = CriaFuncionario();
        LeFuncionario(f);
        ContrataFuncionarioEmpresa(e, f);
    }
}

void ApagaEmpresa(tEmpresa* e) {
    for (int i = 0; i < e->qtdFuncionarios; i++) {
        ApagaFuncionario(e->funcionarios[i]);
    }
    free(e->funcionarios);
    free(e);
}

void ContrataFuncionarioEmpresa(tEmpresa* e, tFuncionario* f) {
    for (int i = 0; i < e->qtdFuncionarios; i++) {      
        if (GetIdFuncionario(f) == GetIdFuncionario(e->funcionarios[i])) {
            printf("A empresa %d ja possui um funcionario com o id %d\n", e->id, GetIdFuncionario(f));   
            ApagaFuncionario(f);
            return;
        }
    }

    e->qtdFuncionarios++;

    if (e->funcionarios == NULL) {
        e->funcionarios = (tFuncionario**) malloc(sizeof(tFuncionario*) * e->qtdFuncionarios);
    } else {
        e->funcionarios = (tFuncionario**) realloc(e->funcionarios, e->qtdFuncionarios * sizeof(sizeof(tFuncionario*)));
    }
   
    e->funcionarios[e->qtdFuncionarios - 1] = f;
} 

void ImprimeEmpresa(tEmpresa *e) { 
    printf("Empresa %d:\n", e->id);
    for (int i = 0; i < e->qtdFuncionarios; i++) {
        ImprimeFuncionario(e->funcionarios[i]);
    }
}
