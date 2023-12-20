#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numOfTasks;
    printf("Digite o numero de tarefas: ");
    scanf("%d", &numOfTasks);

    tAgendaTarefas *agenda = CriaAgendaDeTarefas(numOfTasks);

    for (int i = 0; i < numOfTasks; i++) {
        int priority;
        char taskType;
        char buffer[100];

        scanf("%d %c", &priority, &taskType);
        switch (taskType) {
            case 'I': {
                scanf(" %[^\n]s", buffer);
                tImpr *imprTask = CriaTarefaImprimir(buffer);
                CadastraTarefaNaAgenda(agenda, priority, imprTask, ExecutaTarefaImprimir, DestroiTarefaImprimir);
                break;
            }
            case 'S': {
                float n1, n2;
                scanf("%f %f", &n1, &n2);
                tSoma *somaTask = CriaTarefaSoma(n1, n2);
                CadastraTarefaNaAgenda(agenda, priority, somaTask, ExecutaTarefaSoma, DestroiTarefaSoma);
                break;
            }
            case 'M': {
                float n1, n2;
                scanf("%f %f", &n1, &n2);
                tMult *multTask = CriaTarefaMultiplicar(n1, n2);
                CadastraTarefaNaAgenda(agenda, priority, multTask, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
                break;
            }
            default:
                printf("\nDigite um tipo de tarefa suportado (I/S/M))");
                scanf(" %[^\n]s", buffer);
                i--;
                break;
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}
