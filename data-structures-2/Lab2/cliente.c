#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main(int argc, char const *argv[])
{
    int numero;

    printf("Digite um número N que definirá o numero de chaves: ");
    scanf("%d", &numero);

    srand(time(NULL)); // should only be called once

    Arv* arvore;
    arvore = arv_criavazia();
    for(int i = 0; i < numero; i++) {

        int r =  rand() / 10000; // returns a pseudo-random integer between 0 and RAND_MAX
        // printf("%d\n", r);
        arv_insere(r, arvore);
    }
    int altura = arv_altura(arvore);

    printf("Altura da arvore: %d\n", altura);
    // arv_imprime(arvore);
    printf("\n");

    return 0;
}
