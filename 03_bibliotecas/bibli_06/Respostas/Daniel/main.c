#include "temperature_conversor.h"
#include <stdio.h>

int main() {
    float temperature, convTemperature;
    char escalaAtual, escalaDesejada;

    scanf("%f %c %c", &temperature, &escalaAtual, &escalaDesejada);

    if (escalaAtual == 'c') {
        if (escalaDesejada == 'f') {
            convTemperature = convert_temperature(temperature, convert_celsius_to_fahrenheit);
        } else if (escalaDesejada == 'k') {
            convTemperature = convert_temperature(temperature, convert_celsius_to_kelvin);
        }
    } else if (escalaAtual == 'f') {
        if (escalaDesejada == 'c') {
            convTemperature = convert_temperature(temperature, convert_fahrenheit_to_celsius);
        } else if (escalaDesejada == 'k') {
            convTemperature = convert_temperature(temperature, convert_fahrenheit_to_kelvin);
        }
    } else if (escalaAtual == 'k') {
        if (escalaDesejada == 'c') {
            convTemperature = convert_temperature(temperature, convert_kelvin_to_celsius);
        } else if (escalaDesejada == 'f') {
            convTemperature = convert_temperature(temperature, convert_kelvin_to_fahrenheit);
        }
    }

    if (escalaDesejada == 'c') {
        printf("Temperature: %.2fCº", convTemperature);
    } else if (escalaDesejada == 'f') {
        printf("Temperature: %.2fFº", convTemperature);
    } else if (escalaDesejada == 'k') {
        printf("Temperature: %.2fK", convTemperature);
    } else {
        printf("Escala invalida.\n");
    }

    return 0;
}
