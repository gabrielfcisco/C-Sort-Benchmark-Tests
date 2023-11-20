#include "../include/timSort.h"
#define MIN_MERGE 32

// Função para encontrar o mínimo entre dois números
int
min(int a, int b)
{
    return (a < b) ? a : b;
}

// Função de inserção para ordenar pequenos subarrays
void insertionTimSort(struct data array[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        struct data key = array[i];
        int j = i - 1;

        // Move os elementos do array que são maiores que a chave para uma posição à frente de sua posição atual
        while (j >= left && array[j].key < key.key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

// Função para mesclar dois subarrays ordenados
void mergeTimSort(struct data array[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    struct data *left = (struct data *)malloc(len1 * sizeof(struct data));
    struct data *right = (struct data *)malloc(len2 * sizeof(struct data));

    for (int i = 0; i < len1; i++)
        left[i] = array[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = array[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i].key >= right[j].key) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < len2) {
        array[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

// Função principal do Timsort
void timSort(struct data array[], int n) {
    // Aplica o Insertionsort para subarrays de tamanho 32 ou menos
    for (int i = 0; i < n; i += MIN_MERGE) {
        insertionTimSort(array, i, min((i + MIN_MERGE - 1), (n - 1)));
    }

    // Mescla subarrays criados pelo Insertionsort
    for (int size = MIN_MERGE; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                mergeTimSort(array, left, mid, right);
            }
        }
    }
}