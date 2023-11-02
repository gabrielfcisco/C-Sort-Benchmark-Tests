#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "data.h"

void swapQuick(struct data *a, struct data *b);

int partition(struct data array[], int low, int high);

void quickSort(struct data array[], int low, int high);

#endif