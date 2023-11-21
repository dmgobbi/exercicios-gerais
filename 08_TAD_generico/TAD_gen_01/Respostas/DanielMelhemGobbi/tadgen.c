#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic {
    Type type;
    int numElem;
    void *data;
};

tGeneric* CriaGenerico (Type type, int numElem) {
    tGeneric *gen = (tGeneric*) malloc(sizeof(tGeneric));
    if (gen == NULL) return NULL;

    gen->type = type;
    gen->numElem = numElem;

    if (type == INT) {
        gen->data = (int*) malloc(sizeof(int) * numElem);
    } else if (type == FLOAT) {
        gen->data = (float*) malloc(sizeof(float) * numElem);
    }

    if (gen->data == NULL) {
        free(gen);
        return NULL;
    }

    return gen;
}

void DestroiGenerico (tGeneric* gen) {
    if (gen != NULL) {
        free(gen->data);
        free(gen);
    }
}

void LeGenerico (tGeneric* gen) {
    if (gen != NULL) {
        if (gen->type == INT) {
            for (int i = 0; i < gen->numElem; i++) {
                scanf("%d", &((int*)gen->data)[i]);
            }
        } else if (gen->type == FLOAT) {
            for (int i = 0; i < gen->numElem; i++) {
                scanf("%f", &((float*)gen->data)[i]);
            }
        }
    }
}

void ImprimeGenerico (tGeneric* gen) {
    printf("\nDigite o vetor:\n");
    
    if (gen != NULL) {
        if (gen->type == INT) {
            for (int i = 0; i < gen->numElem; i++) {
                printf("%d ", ((int*)gen->data)[i]);
            }
        } else if (gen->type == FLOAT) {
            for (int i = 0; i < gen->numElem; i++) {
                printf("%.2f ", ((float*)gen->data)[i]);
            }
        }
        printf("\n");
    }
}
