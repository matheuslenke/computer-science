//
// Created by lenke on 18/09/2020.
//

#include "primeNumberInt.h"
#include <stdio.h>
#include <stdlib.h>

int * criaVetorInt(int N) {
    int* vetor = (int*)malloc((N + 1) * sizeof(int));
    for(int i = 2; i <= N; i++) {
        vetor[i] = 1;
    }
    return vetor;
}

void imprimePrimosInt(int *vetor, int N) {
    printf("Os numeros primos sao: \n");
    if(N > 1) {
        printf("1 ");
    }
    for(int i = 2; i < N ; i++) {
        if(vetor[i] == 1) {
            printf("%d ", i);
        }
    }
}

int * encontraPrimosInt(int *vetor, int N) {
    int divisor;
    for(int i = 2; i < N; i++) {
        for(int j = i+1; j< N; j++) {
            if(i != 0 && j != 0) {
                divisor = j % i;
                if(divisor == 0) {
                    vetor[j] = 0;
                }
            } else break;
        }
    }
    return vetor;
}

void liberaVetorInt(int* vetor) {
    free(vetor);
}