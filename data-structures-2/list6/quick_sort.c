//
// Created by lenke on 01/11/2020.
//

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "pilha.h"

#define CUTOFF 30000

double min(double x, double y){
    return x<y ? x : y;
}
double med_aux(double x, double y, double z){
    return z<x ? x : min(z,y);
}
double med(double x, double y, double z){
    return x<y ? med_aux(x, y, z) : med_aux(y, x, z);
}

int median_of_3(Item* a, int lo, int hi) {
    int num1 = (rand() % (hi - lo + 1)) + lo;
    int num2 = (rand() % (hi - lo + 1)) + lo;
    int num3 = (rand() % (hi - lo + 1)) + lo;

    return med(num1, num2, num3);
}

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];
    while(1) {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi) break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo) break;
        if (i >= j) break; // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.
    return j; // Return index of item known to be in place.
}

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

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);
    }
}

//void quick_sort(Item *a, int lo, int hi) {
//    Pilha* pilha = cria_pilha(hi - lo);
////    int cutoff = (hi - lo) / 2;
//    push2(lo, hi, pilha);
//    while(!pilha_vazia(pilha)) {
//        lo = pop(pilha); hi = pop(pilha);
//        if (hi <= lo) continue; // Could add cutoff here.
////        if (hi <= lo + CUTOFF - 1) {
////            insert_sort(a, lo, hi);
////            return;
////        }
//        int i = partition(a, lo, hi);
//        int median = median_of_3(a, lo, hi);
//        exch(a[lo], a[median]);
//        if (i-lo > hi-i) { // Test the size of sub-arrays.
//            push2(lo, i-1, pilha); // Push the larger one.
//            push2(i+1, hi, pilha); // Sort the smaller one first.
//        } else {
//            push2(i+1, hi, pilha);
//            push2(lo, i-1, pilha);
//        }
//    }
//    destroi_pilha(pilha);
//}

// Dijkstra 3-way partitioning
void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo) return;
    Item v = a[lo];
    int lt = lo, gt = hi, i = lo;
    while (i <= gt) {
        if (a[i] < v) {
            exch(a[lt], a[i]);
            lt++; i++;
        } else if (a[i] > v) {
            exch(a[i], a[gt]);
            gt--;
        } else {
            i++;
        }
    }
    quick_sort(a, lo, lt-1);
    quick_sort(a, gt+1, hi);
}

void sort(Item *a, int lo, int hi) {
    shuffle(a, hi-lo+1); // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}