#include <stdio.h>
#include <string.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main() {
    int N, numElementos, numeroProcurado;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &numeroProcurado);
        scanf("%d", &numElementos);
        int vet[numElementos];
        
        for (int j = 0; j < numElementos; j++) {
            scanf("%d", &vet[j]);
        }

        int resultado = ContaOcorrencias(vet, numElementos, numeroProcurado);
        printf("%d\n", resultado);
    }

    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    int resultado = 0;
    
    if (numElementos == 0) {
        return resultado;
    } 
    
    if (vet[--numElementos] == numeroProcurado) {
        resultado++;
    } 

    return resultado + ContaOcorrencias(vet, numElementos, numeroProcurado);
}
