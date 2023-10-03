#include <stdio.h>  
#include <stdlib.h>
#include "calculadora.h"

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Multiplicacao(float num1, float num2);
float Divisao(float num1, float num2);

int main() {
    float num1, num2, resultado;
    char operacao;

    while (1) {
        scanf(" %c", &operacao);
        
        if (operacao == 'f') {
            break;
        }

        if (operacao != 'f' && 
            operacao != 'a' && 
            operacao != 's' && 
            operacao != 'm' && 
            operacao != 'd') {
            printf("Operacao invalida!\n");
            return 1;
        }

        if (scanf("%f %f", &num1, &num2) != 2) {
            printf("Erro ao ler os numeros!\n");
            return 2;
        }

        switch (operacao) {
            case 'a':
                resultado = Calcular(num1, num2, Soma);
                printf("%.2f + %.2f = %.2f\n", num1, num2, resultado); 
                break;
            case 's':
                resultado = Calcular(num1, num2, Subtracao);
                printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 'm':
                resultado = Calcular(num1, num2, Multiplicacao);
                printf("%.2f x %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 'd':
                resultado = Calcular(num1, num2, Divisao);
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
                break;
        }
    }

    return 0;
}

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}
