//
// Created by lenke on 01/10/2020.
//

#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi) {
    Item auxiliar;
    for(int i = 1; i< hi; i++) {
        for(int j = i; j>= 0 && a[j] < a[j - 1]; j--) {
            auxiliar = a[j - 1];
            a[j - 1] = a[j];
            a[j] = auxiliar;
        }
    }
}
