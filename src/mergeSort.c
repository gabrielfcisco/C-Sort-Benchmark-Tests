#include <stdio.h>
#include "../include/mergeSort.h"

void merge(struct data array[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Cria vetores temporários para armazenar os elementos da metade esquerda e direita
    struct data L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Mescla os vetores temporários de volta ao vector original em ordem decrescente
    while (i < n1 && j < n2)
    {
        if (L[i].key >= R[j].key)
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Função de ordenação Merge Sort
void mergeSort(struct data array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Ordena a metade esquerda
        mergeSort(array, left, middle);

        // Ordena a metade direita
        mergeSort(array, middle + 1, right);

        // Mescla as duas metades ordenadas
        merge(array, left, middle, right);
    }
}