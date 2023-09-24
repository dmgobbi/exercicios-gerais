#include <stdio.h>
#include "empresa.h"

#define MAX_FUNCIONARIOS 20

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;   
    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    for (int i = 0; i < MAX_FUNCIONARIOS; i++) {
        empresa.funcionarios[i] = criaFuncionario(-1, -1);
    } 

    return empresa;
}

tEmpresa leEmpresa() {
    tEmpresa empresa;
    tFuncionario funcionario;

    int id, qtdFuncionarios;
    scanf("%d %d", &id, &qtdFuncionarios);

    empresa = criaEmpresa(id);

    for (int i = 0; i < qtdFuncionarios; i++) {
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
    int jaContratado = 0;

    for (int i = 0; i < empresa.qtdFuncionarios; i++) {      
        if (funcionario.id == getIdFuncionario(empresa.funcionarios[i])) {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);   
            jaContratado = 1;
            break;
        }
    }

    if (!jaContratado) {
        empresa.funcionarios[empresa.qtdFuncionarios++] = funcionario;
    }
    
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) { 
    printf("Empresa %d:\n", empresa.id);
    for (int i = 0; i < empresa.qtdFuncionarios; i++) {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}
