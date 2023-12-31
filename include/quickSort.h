#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "data.h"

void swapQuick(struct data *a, struct data *b);

int limitPivot(int low, int high, char limit);

int partition(struct data array[], int low, int high, char limit);

void quickSort(struct data array[], int low, int high, char limit);

#endif