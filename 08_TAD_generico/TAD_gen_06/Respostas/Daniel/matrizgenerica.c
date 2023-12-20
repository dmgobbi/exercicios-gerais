#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrizgenerica {
    int l;
    int c;
    int numByteElem;
    void *elementos;
};

tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem) {
    tMatrizGenerica * m = malloc(sizeof(tMatrizGenerica));
    if (!m) {
        printf("Erro ao alocar memoria para matriz\n");
        return NULL;
    }
    m->l = linhas;
    m->c = colunas;
    m->numByteElem = numByteElem;
    m->elementos = calloc(m->l * m->c, numByteElem);
    if (!m->elementos) {
        printf("Erro ao alocar memoria para o vetor de elementos da matriz\n");
        return NULL;
    }
    return m;
}

void DestroiMatrizGenerica(tMatrizGenerica * m) {
    if (!m) {
        printf("Erro ao destruir matriz\n");
        return;
    }
    free(m->elementos);
    free(m);
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * m) {
    if (m) {
        return m->l;
    } else {
        printf("Erro ao obter numero de linhas da matriz\n");
        return -1;  
    }
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * m) {
    if (m) {
        return m->c;
    } else {
        printf("Erro ao obter numero de colunas da matriz\n");
        return -1;
    }
}

void * ObtemElementoMatrizGenerica(tMatrizGenerica * m, int l, int c) {
    if (m) {
        return m->elementos + (l * (m->c * m->numByteElem) + (c * m->numByteElem));
    } else {
        printf("Erro ao obter elemento da matriz\n");
        return NULL; 
    }
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica * m, int l, int c, void* elem) {
    if (m) {
        void * elemMat = ObtemElementoMatrizGenerica(m, l, c);
        memcpy(elemMat, elem, m->numByteElem);

    } else {
        printf("Erro ao atribuir elemento na matriz\n");
        return;
    }
}

void ImprimirMatrizGenerica(tMatrizGenerica * m, void (imprime_elemento(void*))) {
    if (m) {
        for (int i = 0; i < m->l; i++) {
            for (int j = 0; j < m->c; j++) {
                imprime_elemento(ObtemElementoMatrizGenerica(m, i, j));
                printf(" ");
            }
            printf("\n");
        }
    } else {
        printf("Erro ao imprimir matriz\n");
        return;
    }
}

tMatrizGenerica *MatrizTransposta(tMatrizGenerica *m) {
    if (m) {
        tMatrizGenerica *mT = CriaMatrizGenerica(m->c, m->l, m->numByteElem);
        for (int i = 0; i < m->l; i++) {
            for (int j = 0; j < m->c; j++) {
                AtribuiElementoMatrizGenerica(mT, j, i, ObtemElementoMatrizGenerica(m, i, j));
            }
        }
        return mT;
    } else {
        printf("Erro ao transpor matriz\n");
        return NULL;
    }
}

tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)) {
    if (mat1 && mat2) {
        if (mat1->c == mat2->l) {
            tMatrizGenerica *m = CriaMatrizGenerica(mat1->l, mat2->c, numByteTarget);
            for (int i = 0; i < mat1->l; i++) {
                for (int j = 0; j < mat2->c; j++) {
                    void *elem = ObtemElementoMatrizGenerica(m, i, j);
                    for (int k = 0; k < mat1->c; k++) {
                        void *elem1 = ObtemElementoMatrizGenerica(mat1, i, k);
                        void *elem2 = ObtemElementoMatrizGenerica(mat2, k, j);
                        void *multi_result = multi_elem(elem1, elem2);
                        void *soma_result = soma_elem(elem, multi_result);
                        memcpy(elem, soma_result, numByteTarget);
                        free(soma_result); // Free the memory allocated by soma_elem
                        free(multi_result); // Free the memory allocated by multi_elem
                    }
                    AtribuiElementoMatrizGenerica(m, i, j, elem);
                }
            }
            return m;
        } else {
            printf("Erro ao multiplicar matrizes.\nNumero de colunas da primeira matriz diferente do numero de linhas da segunda matriz\n");
            return NULL;
        }
    } else {
        printf("Erro ao multiplicar matrizes.\nUma das matrizes nao existe\n");
        return NULL;
    }
}

tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)) {
    if (mat2) {
        tMatrizGenerica *m = CriaMatrizGenerica(mat2->l, mat2->c, novoNumByteElem);
        for (int i = 0; i < mat2->l; i++) {
            for (int j = 0; j < mat2->c; j++) {
                void *elem = ObtemElementoMatrizGenerica(mat2, i, j);
                // AtribuiElementoMatrizGenerica(m, i, j, elem);
                void *new_elem = converte_elem(elem);
                AtribuiElementoMatrizGenerica(m, i, j, new_elem);
                free(new_elem); // Free the memory allocated by converte_elem
            }
        }
        return m;
    } else {
        printf("Erro ao converter matriz.\n");
        return NULL;
    }
}