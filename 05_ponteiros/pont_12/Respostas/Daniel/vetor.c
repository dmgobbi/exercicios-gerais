#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeVetor(Vetor *vetor) {
    scanf("%d", &vetor->tamanhoUtilizado);
    for (int i = 0; i < vetor->tamanhoUtilizado; i++) {
        scanf("%d", vetor->elementos + i);

        /* 
            Usa desreferenciacao e aritmetica de ponteiros.
            O operador '&' obtem o endereco de memoria, e a expressao '(vetor->elementos + i)' 
            aponta para esse endereço. O valor lido eh entao armazenado nesse endereco.
            
            // scanf("%d", &*(vetor->elementos + i)); 
        */

        // Usa indexacao de array para ler o valor.
        // scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    int resultado = *vetor->elementos;
    // int resultado = *(vetor->elementos + 0);
    // int resultado = vetor->elementos[0];

    for (int i = 1; i < vetor->tamanhoUtilizado; i++) {
        resultado = op(resultado, *(vetor->elementos + i));
        // resultado = op(resultado, vetor->elementos[i]);
    }
    return resultado;
}
