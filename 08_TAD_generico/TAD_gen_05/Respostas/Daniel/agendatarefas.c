#include "agendatarefas.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int priority;
    void *task;
    void (*execute)(void *);
    void (*destroy)(void *);
} Task;

struct agendatarefas {
    Task *tasks;
    int capacity;
    int size;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *agenda = (tAgendaTarefas *)calloc(1, sizeof(tAgendaTarefas));
    if (agenda) {
        agenda->tasks = (Task *)calloc(numElem, sizeof(Task));
        agenda->capacity = numElem;
        agenda->size = 0;
    }
    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    if (tar) {
        for (int i = 0; i < tar->size; i++) {
            Task currentTask = tar->tasks[i];
            void (*destroyFunc)(void *) = currentTask.destroy;
            void *task = currentTask.task;

            // Call the destroy function for the task
            destroyFunc(task);
        }
        free(tar->tasks);
        free(tar);
    }
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*)) {
    if (tar && tar->size < tar->capacity) {
        Task newTask = {prioridade, tarefa, executa, destroi};
        tar->tasks[tar->size++] = newTask;
    }
}

// Comparison function for qsort
int compareTasks(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return taskB->priority - taskA->priority; // sort in descending order of priority
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {
    // Sort tasks by priority
    qsort(tar->tasks, tar->size, sizeof(Task), compareTasks);

    // Execute tasks
    for (int i = 0; i < tar->size; i++) {
        Task currentTask = tar->tasks[i];
        void (*executeFunc)(void *) = currentTask.execute;
        void *task = currentTask.task;

        // Call the execute function for the task
        executeFunc(task);
    }
}