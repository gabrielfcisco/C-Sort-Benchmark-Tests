#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/data.h"
#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/shellSort.h"
#include "../include/mergeSort.h"
#include "../include/quickSort.h"
#include "../include/timSort.h"

#define TAM_ARRAY 100

int main()
{   
    struct data array[TAM_ARRAY];
    int n = TAM_ARRAY;

    srand(0);

    for(int i = 0; i < n; i++){
        array[i].key = rand();
        array[i].field = rand() %(RAND_MAX - 100 + 1) + 100;
    }

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++)
    {
        printf("key: %d, field: %f\n", array[i].key, array[i].field);
    }
    clock_t begin = clock();

    timSort(array, n);

    clock_t end = clock();
    double timeSpent = (double) (end - begin) / CLOCKS_PER_SEC ;

    printf("\nVetor ordenado em ordem decrescente:\n");
    for (int i = 0; i < n; i++)
    {
        printf("key: %d, field: %f\n", array[i].key, array[i].field);
    }

    printf("\n\n Tempo para ordenação gasto:%lf\n", timeSpent);

    return 0;
}
