#include <stdio.h>
#include "../include/insertionSort.h"

void insertionSort(struct data array[], int n)
{
    int i, j;
    struct data key;

    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        // Para ordenação decrescente, troque ">" por "<"
        while (j >= 0 && array[j].key < key.key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}