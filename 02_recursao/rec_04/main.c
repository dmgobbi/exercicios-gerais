#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

int palindromo(char *string, int tamanho);

int main() {
    char string[MAX_STRING];

    while(scanf("%s", string) == 1) {
        if(palindromo(string, strlen(string))) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}

int palindromo(char *string, int tamanho) {
    if (tamanho <= 1) {
        return 1;
    }

    if (string[0] != string[tamanho - 1]) {
        return 0;
    }
    
    return palindromo(string + 1, tamanho - 2);
}
