//
// Created by lenke on 26/10/2020.
//

#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#define CUTOFF 50000


void insert_sort(Item *a, int lo, int hi) {
    Item auxiliar;
    for(int i = 1; i< hi; i++) {
        for(int j = i; j>= 0 && a[j] < a[j - 1]; j--) {
            auxiliar = a[j - 1];
            a[j - 1] = a[j];
            a[j] = auxiliar;
        }
    }
}


void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copy array
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) { // Merge
        if (i > mid) {
            a[k] = aux[j++];
        }
        else if (j > hi) {
            a[k] = aux[i++];
        }
        else if (less(aux[j], aux[i])) {
            a[k] = aux[j++];
        }
        else a[k] = aux[i++];
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    if (!less(a[mid+1], a[mid])) return;
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = malloc(N * sizeof(Item));
    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    free(aux);
}