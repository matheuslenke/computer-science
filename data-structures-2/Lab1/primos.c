//
// Created by mlcoutinho on 10/03/20.
//

#include "primos.h"
#include <stdio.h>
#include <stdlib.h>

char * criaVetor(int N){
    char* vetor;
    vetor = (char*)malloc((N + 1) * sizeof(char));
    for(int i = 2; i <= N; i++) {
        vetor[i] = 1;
    }
    return vetor;
}


char * encontraPrimos(char *vetor, int N) {
    int divisor;
    for(int i = 2; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(vetor[i] == 1) {
                if(j != 0 && i != 0) {
//                printf("Dividindo %d por %d \n", vetor[j], vetor[i]);
                    divisor = j % i;

                    if(divisor == 0) {
                        vetor[j] = 0;
                    }
                }
            }
            else break;
        }
    }
    return vetor;
}

void imprimePrimo(char *vetor, int n) {
    printf("Os primos são: \n");
    for(int i = 2; i < n; i++) {
        if(vetor[i] != 0) {
            printf("%d\n", i);
        }
    }
}

void liberaVetor(char* vetor) {
    free(vetor);
}