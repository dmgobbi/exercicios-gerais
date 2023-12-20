#include "complex_operations.h"
#include "numcomplexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void* mult_complexo(void* a, void* b) {
    tNumComplexo* num1 = (tNumComplexo*)a;
    tNumComplexo* num2 = (tNumComplexo*)b;
    return MultComplexos(num1, num2);
}

void* soma_complexo(void* a, void* b) {
    tNumComplexo* num1 = (tNumComplexo*)a;
    tNumComplexo* num2 = (tNumComplexo*)b;
    return SomaComplexos(num1, num2);
}