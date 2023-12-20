#include "tarefasoma.h"
#include <stdlib.h>
#include <stdio.h>

// Define the structure for a sum task
struct soma {
    float n1;
    float n2;
};

tSoma* CriaTarefaSoma(float n1, float n2) {
    tSoma *newTask = (tSoma *)malloc(sizeof(tSoma));
    if (newTask) {
        newTask->n1 = n1;
        newTask->n2 = n2;
    } else {
        printf("Erro ao criar tarefa de soma\n");
    }
    return newTask;
}

void ExecutaTarefaSoma(void *sum) {
    if (sum) {
        tSoma *sumTask = (tSoma *)sum;
        float result = sumTask->n1 + sumTask->n2;
        printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", sumTask->n1, sumTask->n2, result);
    } else {
        printf("Erro ao executar tarefa de soma\n");
    }
}

void DestroiTarefaSoma(void *sum) {
    if (sum) {
        free(sum);
    } else {
        printf("Erro ao destruir tarefa de soma\n");
    }
}
