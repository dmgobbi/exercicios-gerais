#include "tarefamultiplica.h"
#include <stdlib.h>
#include <stdio.h>

// Define the structure for a multiplication task
struct mult {
    float n1;
    float n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2) {
    tMult *newTask = (tMult *)malloc(sizeof(tMult));
    if (newTask) {
        newTask->n1 = n1;
        newTask->n2 = n2;
    } else {
        printf("Erro ao criar tarefa de multiplicacao\n");
    }
    return newTask;
}

void ExecutaTarefaMultiplicar(void *mult) {
    if (mult) {
        tMult *multiplicationTask = (tMult *)mult;
        float result = multiplicationTask->n1 * multiplicationTask->n2;
        printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", multiplicationTask->n1, multiplicationTask->n2, result);
    } else {
        printf("Erro ao executar tarefa de multiplicacao\n");
    }
}

void DestroiTarefaMultiplicar(void *mult) {
    if (mult) {
        free(mult);
    } else {
        printf("Erro ao destruir tarefa de multiplicacao\n");
    }
}

