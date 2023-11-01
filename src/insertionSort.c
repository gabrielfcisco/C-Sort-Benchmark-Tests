#include <stdio.h>
#include "insertionSort.h"

void
insertionSort(struct data vector[], int n) {
    int i, j;
    struct data key;

    for (i = 1; i < n; i++) {
        key = vector[i];
        j = i - 1;

        // Para ordenação decrescente, troque ">" por "<"
        while (j >= 0 && vector[j].key < key.key) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
}