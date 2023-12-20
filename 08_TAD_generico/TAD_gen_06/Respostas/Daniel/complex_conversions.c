#include "complex_conversions.h"
#include "numcomplexo.h"
#include <stdio.h>
#include <stdlib.h>


void* ConverteIntParaComplexo(void* elem) {
    int* inteiro = (int*) elem;
    tNumComplexo* complexo = CriaNumComplexo((float)*inteiro, 0.0);
    return complexo;
}

void* ConverteFloatParaComplexo(void* elem) {
    float* flutuante = (float*) elem;
    tNumComplexo* complexo = CriaNumComplexo(*flutuante, 0.0);
    return complexo;
}

void* ConverteDoubleParaComplexo(void* elem) {
    double* duplo = (double*) elem;
    tNumComplexo* complexo = CriaNumComplexo((float)*duplo, 0.0);
    return complexo;
}

void* ConverteCharParaComplexo(void* elem) {
    char* caractere = (char*) elem;
    tNumComplexo* complexo = CriaNumComplexo((float)*caractere, 0.0);
    return complexo;
}
