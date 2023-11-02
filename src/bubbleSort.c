#include <stdio.h>
#include "../include/bubbleSort.h"

void swapBubble(struct data *a, struct data *b)
{
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação Bubble Sort
void bubbleSort(struct data array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Para ordenação decrescente, troque ">" por "<"
            if (array[j].key < array[j + 1].key)
            {
                swapBubble(&array[j], &array[j + 1]);
            }
        }
    }
}