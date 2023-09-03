#include "string_utils.h"
#include <stdio.h>

int string_length(char *str) {
    int length = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

void string_copy(char *src, char *dest) {
    int length = string_length(src);
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void string_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void string_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void string_reverse(char *str) {
    int length = string_length(str);
    for (int i = length - 2, j = 0; i > j; i--, j++) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
