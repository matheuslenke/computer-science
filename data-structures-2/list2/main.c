
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main(int argc, char const *argv[]) {
    int numero;

    printf("Digite um número N que definirá o numero de chaves: ");
    scanf("%d", &numero);

    srand(time(NULL)); // should only be called once


    Arv *arvore;
    arvore = arv_criavazia();
    for (int i = 0; i < numero; i++) {

        int r = rand() / 10000000; // returns a pseudo-random integer between 0 and RAND_MAX
        // printf("%d\n", r);
        arv_insere(r, arvore);
    }
    int altura = arv_altura(arvore);

    printf("Altura da arvore: %d\n", altura);
    arv_imprime(arvore);
    printf("\n");
//
    printf("Pre-order: \n");

    clock_t start = clock();

    rec_preorder(arvore, visita_arvore);

//    printf("In-order: \n");
//
//    rec_inorder(arvore, visita_arvore);
//
//    printf("Post-order: \n");
//
//    rec_postorder(arvore, visita_arvore);
//
//    printf("Agora sem regressão\n");
    clock_t end = clock();

    clock_t start_iterative = clock();
//
//
//    printf("Pre-order: \n");
//
//    iterative_rec_preorder(arvore, visita_arvore);
//
//    printf("In-order: \n");
//
//    iterative_rec_inorder(arvore, visita_arvore);
//
//    printf("Post-order: \n");
//
//    iterative_rec_postorder(arvore, visita_arvore);

    clock_t end_iterative = clock();

    printf("Agora em non-recursive level-order traversal\n");

    print_level_order(arvore);


    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf (" regressao: % lf \n" , seconds );

    double secondsIterative = (( double ) end_iterative - start_iterative ) / CLOCKS_PER_SEC ;
    printf (" iterativo: % lf \n" , secondsIterative );

    return 0;
}