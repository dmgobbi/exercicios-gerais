#include "tarefaimprime.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the structure for a print task
struct impr {
    char *msg;
};

tImpr* CriaTarefaImprimir(char *msg) {
    tImpr *newTask = (tImpr *)malloc(sizeof(tImpr));
    if (newTask) {
        // newTask->msg = strdup(msg);  // Alternative to malloc + strcpy
        newTask->msg = malloc(strlen(msg) + 1);
        if (newTask->msg) {
            strcpy(newTask->msg, msg);
            // memcpy(newTask->msg, msg, strlen(msg) + 1); // Alternative to strcpy
        } else {
            printf("Erro ao alocar memoria para mensagem\n");
            free(newTask);
            newTask = NULL;
        }
    } else {
        printf("Erro ao criar tarefa de impressao\n");
    }
    return newTask;
}

void ExecutaTarefaImprimir(void *imp) {
    if (imp) {
        tImpr *printTask = (tImpr *)imp;
        printf("\n%s", printTask->msg);
    } else {
        printf("Erro ao executar tarefa de impressao\n");
    }
}

void DestroiTarefaImprimir(void *imp) {
    if (imp) {
        tImpr *printTask = (tImpr *)imp;
        free(printTask->msg);  // Free the duplicated message
        free(printTask);
    } else {
        printf("Erro ao destruir tarefa de impressao\n");
    }
}
