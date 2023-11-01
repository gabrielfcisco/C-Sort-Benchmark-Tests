#include <stdio.h>
#include <stdlib.h>
#include "../include/data.h"
#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/shellSort.h"
// #include "mergeSort.h"
// #include "quickSort.h"

// Definição da struct




int main() {
    struct data vetor[] = {
        {3, 42},
        {1, 17},
        {4, 32},
        {2, 88},
        {5, 56}
    };
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("key: %d, field: %d\n", vetor[i].key, vetor[i].field);
    }

    bubbleSort(vetor, n);

    printf("\nVetor ordenado em ordem decrescente:\n");
    for (int i = 0; i < n; i++) {
        printf("key: %d, field: %d\n", vetor[i].key, vetor[i].field);
    }

    return 0;
}
