#include <stdio.h>
#include "primos.h"

int main() {
    int numero;

    printf("Digite um número para encontrar seus primos: ");
    scanf("%d", &numero);

    char* vetor = criaVetor(numero);

//    printf("O vetor é: ");
//    for(int i = 0; i < numero; i++) {
//        printf("%d ", vetor[i]);
//    }

    vetor = encontraPrimos(vetor, numero);

    imprimePrimo(vetor, numero);

    liberaVetor(vetor);

    return 0;
}