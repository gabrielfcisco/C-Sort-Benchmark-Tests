#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "data.h"

// Função para trocar dois elementos da struct
void swapBubble(struct data *a, struct data *b);
// Função de ordenação Bubble Sort
void bubbleSort(struct data vector[], int n);

#endif
