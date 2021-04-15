//
// Created by lenke on 18/09/2020.
//

#include "primeNumberBool.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool * criaVetorBool(int N) {
    bool* vetor = (bool*)malloc((N + 1) * sizeof(bool));
    for(int i = 2; i <= N; i++) {
        vetor[i] = true;
    }
    return vetor;
}

void imprimePrimosBool(bool *vetor, int N) {
    printf("Os numeros primos sao: \n");
    if(N > 1) {
        printf("1 ");
    }
    for(int i = 2; i < N ; i++) {
        if(vetor[i] == true) {
            printf("%d ", i);
        }
    }
}

bool * encontraPrimosBool(bool *vetor, int N) {
    int divisor;
    for(int i = 2; i < N; i++) {
        for(int j = i+1; j< N; j++) {
            if(i != 0 && j != 0) {
                divisor = j % i;
                if(divisor == 0) {
                    vetor[j] = false;
                }
            } else break;
        }
    }
    return vetor;
}

void liberaVetorBool(bool *vetor) {
    free(vetor);
}
