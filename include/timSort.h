#ifndef TIMSORT_H
#define TIMSORT_H

#include <stdlib.h>
#include "data.h"

int min(int a, int b);
void insertionTimSort(struct data array[], int left, int right);
void mergeTimSort(struct data array[], int l, int m, int r);
void timSort(struct data array[], int n);

#endif