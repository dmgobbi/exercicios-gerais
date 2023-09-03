#include "string_utils.h"
#include <stdio.h>

#define MAX_STRING 100

int main() {
    char str[MAX_STRING];
    int opcao;

    scanf("%[^\n]\n", str);

    while (1) {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Tamanho da string: %d\n\n", string_length(str));
                break;
            case 2:
                char strCopy[MAX_STRING];
                string_copy(str, strCopy);
                printf("String copiada: %s\n\n", strCopy);
                break;
            case 3:
                string_upper(str);
                printf("String convertida para maiusculas: %s\n\n", str);
                break;
            case 4:
                string_lower(str);
                printf("String convertida para minusculas: %s\n\n", str);
                break;
            case 5:
                string_reverse(str);
                printf("String invertida: \n%s\n\n", str);
                break;
            case 6:
                return 0;
            default:
                printf("Opcao invalida.\n\n");
        }
    }

    return 0;
}
