//
// Created by Matheus Lenke on 04/11/19.
//

#include <stdio.h>
#include <stdlib.h>

int main (void) {

#include "abb.h"

    Arv* a = NULL;
    a = arv_insere(4, a);
    arv_insere(5, a);
    arv_insere(6, a);
    arv_insere(1, a);
    arv_insere(14, a);
    arv_insere(7, a);
    arv_insere(432, a);
    arv_imprime(a);

    printf("\n");

    retira(a, 4);
    arv_imprime(a);
    printf("\n");
    retira(a, 5);
    printf("\n");
    arv_imprime(a);
    retira(a, 432);
    printf("\n");
    arv_imprime(a);
    printf("\n");
    retira(a, 0);
    arv_imprime(a);
    printf("\n Buscando na arvore: \n");
    Arv* b = arv_busca(a, 7);
    arv_imprime(b);

    arv_libera(a);
    free(a);

    return 0;
}
