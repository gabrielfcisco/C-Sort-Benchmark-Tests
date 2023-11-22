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

#define TAM_ARRAY 100000

int main()
{   
    int n = TAM_ARRAY;
    struct data *array = malloc(n*sizeof(struct data));

    srand(0);

    for(int i = 0; i < n; i++){
        array[i].key = rand();
        array[i].field = rand() %(RAND_MAX - 100 + 1) + 100;
    }

    // printf("Vetor original:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("key: %d, field: %f\n", array[i].key, array[i].field);
    // }
    printf("\nExecutando ordenacao...");

    clock_t begin = clock();

    insertionSort(array, n);

    clock_t end = clock();
    double timeSpent = (double) (end - begin) / CLOCKS_PER_SEC ;

    // printf("\nVetor ordenado em ordem decrescente:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("key: %d, field: %f\n", array[i].key, array[i].field);
    // }

    printf("\nOrdenacao concluida!\n\nTempo para ordenação gasto:%lf\n", timeSpent);

    free(array);

    return 0;
}
