/** @file */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int gives_5() {
    return 5;
}

/// Print each element of int array
void printa(int size, int* arr) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
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

/// Persistent insertion sort. Sorted array is in `new_arr`
void insertion_sort(int s, int* arr, int* new_arr) {
    int j;
    new_arr[0] = arr[0];

    for (int i=1; i < s; i++) {
        j = i - 1;
        while ((j > -1) && (arr[i] < new_arr[j])) {
            new_arr[j+1] = new_arr[j];
            j--;
        }
        new_arr[j+1] = arr[i];
        printa(s, new_arr);
    }
    return;
}
