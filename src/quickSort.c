#include <stdio.h>
#include "../include/quickSort.h"

// Função para trocar dois elementos da struct
void swapQuick(struct data *a, struct data *b) {
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

// Função que encontra a posição correta do pivô no vetor
int partition(struct data array[], int low, int high) {
    int pivot = array[high].key;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j].key >= pivot) {
            i++;
            swapQuick(&array[i], &array[j]);
        }
    }

    swapQuick(&array[i + 1], &array[high]);
    return (i + 1);
}

// Função de ordenação Quick Sort
void quickSort(struct data array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}