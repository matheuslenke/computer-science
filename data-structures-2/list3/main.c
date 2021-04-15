#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>


extern void sort(Item *a, int lo, int hi);

void print_vector(Item *a, int N) {
    for(int i = 0; i < N; i ++) {
        printf("%d ", a[i]);
    }
}

void sort_vetor(Item* vetor, int tamanho) {
    clock_t start = clock();
    sort(vetor, 0, tamanho);
    clock_t end = clock();

    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("\ntempo: % lf s \n" , seconds );
}

int main() {
//    int N;
//    printf("Entre o numero N de itens a serem ordenados:");
//    scanf("%d", &N);
//
//    printf("Digite os %d numeros\n", N);
//    Item* vetor = (Item*)malloc((N + 1 )* sizeof(Item));

    FILE* file = fopen("in/nearly_sorted/1Knearly_sorted.txt", "r");

    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    Item* vetor = (Item*)malloc(1000 * sizeof(Item));
    for(int i = 0; i < 1000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }

    printf("\n 1K nearly sorted: \n");
    sort_vetor(vetor, 1000);
    free(vetor);
    fclose(file);

    // 10K nearly sorted
    file = fopen("in/nearly_sorted/10Knearly_sorted.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }
    vetor = (Item*)malloc(10000 * sizeof(Item));
    for(int i = 0; i < 10000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 10K nearly sorted: \n");
    sort_vetor(vetor, 10000);
    free(vetor);
    fclose(file);

    // 100K nearly sorted
    file = fopen("in/nearly_sorted/100Knearly_sorted.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }
    vetor = (Item*)malloc(100000 * sizeof(Item));
    for(int i = 0; i < 100000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 100K nearly sorted: \n");
    sort_vetor(vetor, 100000);
    free(vetor);
    fclose(file);

    /**
     * REVERSE SORTED
     */
     printf("\nREVERSE SORTED!\n");

    file = fopen("in/reverse_sorted/1Kreverse_sorted.txt", "r");

    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    vetor = (Item*)malloc(1000 * sizeof(Item));
    for(int i = 0; i < 1000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }

    printf("\n 1K reverse sorted: \n");
    sort_vetor(vetor, 1000);
    free(vetor);
    fclose(file);

    // 10K reverse sorted
    file = fopen("in/reverse_sorted/10Kreverse_sorted.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }
    vetor = (Item*)malloc(10000 * sizeof(Item));
    for(int i = 0; i < 10000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 10K reverse sorted: \n");
    sort_vetor(vetor, 10000);
    free(vetor);
    fclose(file);

    // 100K reverse sorted
    file = fopen("in/reverse_sorted/100Kreverse_sorted.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    vetor = (Item*)malloc(100000 * sizeof(Item));
    for(int i = 0; i < 100000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 100K reverse sorted: \n");
    sort_vetor(vetor, 100000);
    free(vetor);
    fclose(file);


    /**
  * SORTED
  */
    printf("\nSORTED!\n");

    file = fopen("in/sorted/1Ksorted.txt", "r");

    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    vetor = (Item*)malloc(1000 * sizeof(Item));
    for(int i = 0; i < 1000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }

    printf("\n 1K sorted: \n");
    sort_vetor(vetor, 1000);
    free(vetor);
    fclose(file);

    // 10K reverse sorted
    file = fopen("in/sorted/10Ksorted.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }
    vetor = (Item*)malloc(10000 * sizeof(Item));
    for(int i = 0; i < 10000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 10K sorted: \n");
    sort_vetor(vetor, 10000);
    free(vetor);
    fclose(file);

    // 100K reverse sorted
    file = fopen("in/sorted/100Ksorted.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    vetor = (Item*)malloc(100000 * sizeof(Item));
    for(int i = 0; i < 100000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 100K sorted: \n");
    sort_vetor(vetor, 100000);
    free(vetor);
    fclose(file);

    /**
 * UNIF RANDOM
 */
    printf("\nUNIF RANDOM!\n");

    file = fopen("in/unif_rand/1Kunif_rand.txt", "r");

    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    vetor = (Item*)malloc(1000 * sizeof(Item));
    for(int i = 0; i < 1000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }

    printf("\n 1K unif_rand: \n");
    sort_vetor(vetor, 1000);
    free(vetor);
    fclose(file);

    // 10K reverse unif_rand
    file = fopen("in/unif_rand/10Kunif_rand.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }
    vetor = (Item*)malloc(10000 * sizeof(Item));
    for(int i = 0; i < 10000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 10K unif_rand: \n");
    sort_vetor(vetor, 10000);
    free(vetor);
    fclose(file);

    // 100K reverse unif_rand
    file = fopen("in/unif_rand/100Kunif_rand.txt", "r");
    if(!file) {
        printf("Falha ao abrir arquivo");
        exit;
    }

    vetor = (Item*)malloc(100000 * sizeof(Item));
    for(int i = 0; i < 100000; i ++){
        fscanf(file,"%d\n", &vetor[i]);
    }
    printf("\n 100K unif_rand: \n");
    sort_vetor(vetor, 100000);
    free(vetor);
    fclose(file);

    return 0;
}
