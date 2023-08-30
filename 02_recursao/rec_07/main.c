#include <stdio.h>

int somaDigitos(int n);

int main() {
    int N;
    scanf("%d", &N);
    int resultado = somaDigitos(N);
    printf("%d\n", resultado);
    return 0;
}

int somaDigitos(int n) {
    if (n == 0) {
        return n;
    }

    int numero = n / 10;
    int unidade = n % 10; 
    
    return unidade + somaDigitos(numero);
}
