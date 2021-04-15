//
// Created by lenke on 18/09/2020.
//

#include "primeNumberBit.h"
#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"


bitmap retornaPrimosBit(int N) {
    bitmap bm = bitmapInit(N);

    for(int i = 0; i < N; i++) {
        bitmapAppendLeastSignificantBit(&bm, 0);
    }

    int divisor;
    for(int i = 2; i < N; i++) {
        for(int j = i+1; j< N; j++) {
            if(i != 0 && j != 0) {
                divisor = j % i;
                if(divisor == 0) {
                    bitmapSetBit(&bm, j, 1);
//                    printf("Setting bit %d value 0", j);
//                    printf("bit #%d = %0xh\n", j, bitmapGetBit(bm, j));
                }
            } else break;
        }
    }

    return bm;
}

void imprimePrimosBit(bitmap vetor, int N) {
    bitmap compara = bitmapInit(2);
    bitmapAppendLeastSignificantBit(&compara, 0);
    bitmapAppendLeastSignificantBit(&compara, 1);


    printf("Os numeros primos sao: \n");
    if(N > 1) {
        printf("1 ");
    }
    for(int i = 2; i < N ; i++) {
        if(!(bitmapGetBit(vetor, i) & 0x01u)) {
            printf("%d ", i);
        }
    }
}


