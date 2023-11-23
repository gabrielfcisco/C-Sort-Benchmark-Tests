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

int main()

{   
    for (int i = 0; i<6; i++){

        inProcess(10000, i);
        inProcess(50000, i);
        inProcess(100000, i);
        inProcess(500000, i);
        inProcess(1000000, i);
    }

   return 0;
}

double inProcess(int n, int f) {

    struct data *array = malloc(n*sizeof(struct data));

    clock_t begin;
    clock_t end;

    for (int i = 0; i < 10; i++)
    {
        srand(i*10);

        for(int j = 0; j < n; j++){
            array[j].key = rand();
            array[j].field = rand() % (RAND_MAX - 100 + 1) + 100;
        }

        // printf("Vetor original:\n");
        // for (int i = 0; i < n; i++)
        // {
        //     printf("key: %d, field: %f\n", array[i].key, array[i].field);
        // }
        printf("\nExecutando ordenacao... [%d] Método [%d]", i+1, f);

        switch (f) {

            case 0:

                begin = clock();
            
                insertionSort(array, n);

                end = clock();

            break;

            case 1:

                begin = clock();
            
                bubbleSort(array, n);

                end = clock();

            break;

            case 2:

                begin = clock();
            
                shellSort(array, n);

                end = clock();

            break;

            case 3:

                begin = clock();
            
                mergeSort(array, 0, n);

                end = clock();

            break;

            case 4:

                begin = clock();
            
                quickSort(array, 0, n, h);

                end = clock();

            break;

            case 5:

                begin = clock();
            
                timSort(array, n);

                end = clock();

            break;

        }
        
        double timeSpent = (double) (end - begin) / CLOCKS_PER_SEC ;

        // printf("\nVetor ordenado em ordem decrescente:\n");
        // for (int i = 0; i < n; i++)
        // {
        //     printf("key: %d, field: %f\n", array[i].key, array[i].field);
        // }

        printf("\nOrdenacao concluida!\n\nTempo para ordenação gasto:%lf\n", timeSpent);

        free(array);
    }
    return 0;


}