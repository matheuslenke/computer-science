#include <stdio.h>
#include "arvvar.h"


int main() {

    ArvVar* a = arvv_cria('a');
    ArvVar* b = arvv_cria('b');
    ArvVar* c = arvv_cria('c');
    ArvVar* d = arvv_cria('d');
    ArvVar* e = arvv_cria('e');
    ArvVar* f = arvv_cria('f');
    ArvVar* g = arvv_cria('g');
    ArvVar* h = arvv_cria('h');
    ArvVar* i = arvv_cria('i');
    ArvVar* j = arvv_cria('j');



    arvv_insere(c, d);
    arvv_insere(b, e);
    arvv_insere(b, c);
    arvv_insere(i, j);
    arvv_insere(g, i);
    arvv_insere(g, h);
    arvv_insere(a, g);
    arvv_insere(a, f);
    arvv_insere(a, b);

    arvv_imprime (a);
    printf("\n");

    if(arvv_pertence(a, 'g'))
        printf("Achei o g ;) \n");
    else
        printf("Nao achei o g... :( \n");

    if(arvv_pertence(a, 'z'))
        printf("Achei o z ;) \n");
    else
        printf("Nao achei o z... :( \n");

    int folhas = arvv_folhas(a);
    printf("Essa arvore possui %d folhas\n", folhas);

    int altura = arvv_altura(a);
    printf("A altura da arvore a eh %d\n", altura);
    altura = arvv_altura(g);
    printf("A altura da arvore g eh %d\n", altura);

    arvv_libera(a);
    return 0;
}