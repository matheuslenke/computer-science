//
// Created by lenke on 18/09/2020.
//

#include "primeNumber.h"
#include <stdio.h>
#include <stdlib.h>

char * criaVetor(int N) {
    char* vetor = (char*)malloc((N + 1) * sizeof(char));
    for(int i = 2; i <= N; i++) {
        vetor[i] = 1;
    }
    return vetor;
}

void imprimePrimos(char *vetor, int N) {
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

char * encontraPrimos(char *vetor, int N) {
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

void liberaVetor(char* vetor) {
    free(vetor);
}