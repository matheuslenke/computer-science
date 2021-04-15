#include <stdio.h>
#include <stdlib.h>
#include "primeNumber.h"
#include "primeNumberInt.h"
#include "primeNumberBool.h"
#include "primeNumberBit.h"
#include "bitmap.h"

int main() {
    int N;
    printf("Digite um número N para encontrar os primos até ele:");
    scanf("%d", &N);

//    char* vetor = criaVetor(N);
//    vetor = encontraPrimos(vetor, N);
//    imprimePrimos(vetor, N);
//    liberaVetor(vetor);
//
//    printf("\n Agora em inteiro: \n");
//
//    int* vetorInt = criaVetorInt(N);
//    vetorInt = encontraPrimosInt(vetorInt, N);
//    imprimePrimosInt(vetorInt, N);
//    liberaVetorInt(vetorInt);

//    printf("\n Agora em Boolean: \n");
//
//    bool* vetorBool = criaVetorBool(N);
//    for(int i = 2 ; i< N ; i++) {
//        printf("%d\n", vetorBool[i]);
//    }
//    vetorBool = encontraPrimosBool(vetorBool, N);
//    imprimePrimosBool(vetorBool, N);
//    liberaVetorBool(vetorBool);

//    printf("\n Agora em Bit: \n");

    bitmap vetorBit = retornaPrimosBit(N);
//    vetorBit = encontraPrimosBit(vetorBit, N);
//    imprimePrimosBit(vetorBit, N);

//    free(&vetorBit);
    return 0;
}
