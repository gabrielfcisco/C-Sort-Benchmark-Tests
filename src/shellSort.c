#include <stdio.h>
#include "../include/shellSort.h"

void shellSort(struct data array[], int n)
{
    int gap, i, j;
    struct data temp;

    // Define o tamanho do gap inicial
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap].key < temp.key; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}