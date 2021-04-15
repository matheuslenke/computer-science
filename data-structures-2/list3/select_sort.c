//
// Created by lenke on 01/10/2020.
//
#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi) {
    Item menor;
    int posicao_menor = 0;
    Item auxiliar;
    int trocou = 0;
    for(int i = lo; i< hi; i++) {
        menor = a[i];
        for(int j = i + 1; j< hi; j++) {
            if(a[j] < menor) {
                menor = a[j];
                posicao_menor = j;
                trocou = 1;
            }
        }
        if(trocou == 1) {
            auxiliar = a[i];
            a[i] = menor;
            a[posicao_menor] = auxiliar;
            trocou = 0;
        }
    }
}
