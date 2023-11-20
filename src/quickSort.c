#include <stdio.h>
#include "../include/quickSort.h"

// Função para trocar dois elementos da struct
void swapQuick(struct data *a, struct data *b) {
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô considerando um limite inferior, superior ou do meio
int limitPivot(int low, int high, char limit) {
    switch (limit) {
        case 'l': // Escolhe o primeiro elemento como pivô
            return low;
        case 'm': // Escolhe o elemento do meio como pivô
            return low + (high - low) / 2;
        case 'h': // Escolhe o último elemento como pivô
            return high;
        default:
            return low;
    }
}

// Função que encontra a posição correta do pivô no vetor
int partition(struct data array[], int low, int high, char limit) {
    int index = limitPivot(low, high, limit);
    int pivot = array[index].key;

    swapQuick(&array[index], &array[high]);
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
void quickSort(struct data array[], int low, int high, char limit) {
    if (low < high)
    {
        int pi = partition(array, low, high, limit);

        quickSort(array, low, pi - 1, limit);
        quickSort(array, pi + 1, high, limit);
    }
}