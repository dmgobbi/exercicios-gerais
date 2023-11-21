#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

int main() {
    float xC, yC, raio, xP, yP;

    scanf("%f %f %f %f %f", &xC, &yC, &raio, &xP, &yP);

    tCirculo circulo = Circulo_Cria(xC, yC, raio);
    tPonto ponto = Pto_Cria(xP, yP);

    int resultado = Circulo_Interior(circulo, ponto);

    printf("%d\n", resultado);

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}
