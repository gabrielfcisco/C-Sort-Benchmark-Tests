#include <stdio.h>
#include "../include/shellSort.h"

void
shellSort(struct data vector[], int n) {
    int gap, i, j;
    struct data temp;

    // Define o tamanho do gap inicial
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = vector[i];
            for (j = i; j >= gap && vector[j - gap].key < temp.key; j -= gap) {
                vector[j] = vector[j - gap];
            }
            vector[j] = temp;
        }
    }
}