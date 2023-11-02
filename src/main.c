#include <stdio.h>
#include <stdlib.h>
#include "../include/data.h"
#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/shellSort.h"
#include "../include/mergeSort.h"
#include "../include/quickSort.h"

int main()
{
    struct data array[] = {
        {3, 42},
        {1, 17},
        {4, 32},
        {1, 88},
        {5, 56}};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++)
    {
        printf("key: %d, field: %f\n", array[i].key, array[i].field);
    }

    shellSort(array, n);

    printf("\nVetor ordenado em ordem decrescente:\n");
    for (int i = 0; i < n; i++)
    {
        printf("key: %d, field: %f\n", array[i].key, array[i].field);
    }

    return 0;
}
