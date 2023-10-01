#include <stdio.h> 
#include <stdlib.h>
#include "evento.h" 
 
int main() { 
    Evento eventos[MAX_EVENTOS]; 
    int indiceA, indiceB; 
    int numEventos = 0, opcao = 0; 

    printf("\n===== Menu =====\n"); 
    printf("1 - Cadastrar um evento\n"); 
    printf("2 - Exibir todos os eventos\n"); 
    printf("3 - Trocar data de um evento\n"); 
    printf("4 - Trocar a posicao entre dois eventos\n"); 
    printf("5 - Sair\n"); 
 
    while (1) { 
        scanf("%d", &opcao); 

        switch (opcao) { 
            case 1: 
                cadastrarEvento(eventos, &numEventos); 
                break; 
            case 2: 
                exibirEventos(eventos, &numEventos); 
                break; 
            case 3: 
                trocarDataEvento(eventos, &numEventos); 
                break; 
            case 4: 
                scanf("%d %d", &indiceA, &indiceB);  
                trocarIndicesEventos(eventos, &indiceA, &indiceB, &numEventos); 
                break; 
            case 5: 
                printf("Saindo...\n"); 
                exit(0);
            default: 
                printf("Opcao invalida!\n"); 
        } 
    } 
    return 0; 
} 
