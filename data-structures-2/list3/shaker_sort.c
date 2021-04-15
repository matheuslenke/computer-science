//
// Created by lenke on 01/10/2020.
//
#include "item.h";

void sort(Item *a, int lo, int hi) {
    Item auxiliar;
    int trocou = 0;
    for(int i = 0; i< hi / 2; i++) {
        for(int j = hi - 1 - i; j> i; j--) {
            if(a[j] < a[j-1]) {
                auxiliar = a[j - 1];
                a[j - 1] = a[j];
                a[j] = auxiliar;
                trocou = 1;
            }
        }
        for(int j = i; j< hi - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                auxiliar = a[j + 1];
                a[j + 1] = a[j];
                a[j] = auxiliar;
                trocou = 1;
            }
        }
        if(trocou == 0) {
            break;
        }
        trocou = 0;
    }
}
