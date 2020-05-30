// NOTE: run `make tooling` if getting CCLS warnings
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int gives_5() {
    return 5;
}

int arrcmp(int s, int* arr1, int* arr2) {
    int is_equal = 1;
    for (int i = 0; i < s; i++) {
        is_equal = is_equal && arr1[i] == arr2[i];
    }
    return is_equal;
}
