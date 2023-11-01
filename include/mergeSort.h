#ifndef MERGESORT_H
#define MERGESORT_H

#include "data.h"

void merge(struct data vector[], int left, int middle, int right);

void mergeSort(struct data vector[], int left, int right);

#endif