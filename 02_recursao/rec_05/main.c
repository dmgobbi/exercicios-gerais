#include <stdio.h>

int fatorial(int n);

int main() {
    int n;
    scanf("%d", &n);
    int resultado = fatorial(n);
    printf("%d\n", resultado);
    return 0;
}

int fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fatorial(n - 1);
}
