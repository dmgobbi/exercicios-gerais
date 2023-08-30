#include "esfera_utils.h"
#include <stdio.h>

int main() {
    float raio;
    scanf("%f", &raio);

    float area = calcula_area(raio);
    float volume = calcula_volume(raio);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}
