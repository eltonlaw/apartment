/** @file */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int gives_5() {
    return 5;
}

/// Compare two int arrays, returning 1 if all indexes up to `s`
/// are equal between `arr1` and `arr2`
int arrcmp(int s, int* arr1, int* arr2) {
    int is_equal = 1;
    for (int i = 0; i < s; i++) {
        is_equal = is_equal && arr1[i] == arr2[i];
    }
    return is_equal;
}
