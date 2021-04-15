//
// Created by 2019202297 on 21/10/19.
//
#include <stdio.h>
#include "arvore.h"
#include <stdlib.h>
#include <string.h>

struct arv {
    char info;
    Arv* esquerda;
    Arv* direita;
};

Arv* arv_criavazia (void) {
    return NULL;
}

Arv* arv_cria (char c, Arv* e, Arv* d) {
    Arv* arvore;
    arvore = (Arv*) malloc(sizeof(Arv));
    arvore->esquerda = e;
    arvore->direita = d;
    arvore->info = c;
    return arvore;
}


Arv* arv_libera (Arv* a) {
    if(arv_vazia(a)) {
        return;
    }
    if(a->esquerda == NULL && a->direita == NULL) {
        free(a);
    }
    else{
        arv_libera(a->esquerda);
        arv_libera(a->direita);
    }
}


int arv_vazia (Arv* a) {
    return (a==NULL) ? 1 : 0;
}

int arv_pertence (Arv* a, char c) {
    if(arv_vazia(a)) {
        return 0;
    }
    if(a->info == c) {
        return 1;
    }
    else if (!arv_vazia(a->esquerda)) {
        return arv_pertence(a->esquerda, c);
    }
    else if(!arv_vazia(a->direita)){
       return arv_pertence(a->esquerda, c);
    }

    return 0;

}

void arv_imprime (Arv* a) {
    printf("<");
    if (a != NULL) {
        printf("%c", a->info);
        arv_imprime(a->esquerda);
        arv_imprime(a->direita);
    }
    printf(">");

}


Arv* arv_pai (Arv* a, char c) {
    if(arv_vazia(a)) {
        return 0;
    }
    if(a->esquerda->info == c || a->direita->info == c) {
        return a;
    }
    else {
       return arv_pai(a->esquerda, c) || arv_pai(a->direita, c);
    }
}


int folhas (Arv* a) {
    if(arv_vazia(a)) {
        return 0;
    }
    if(a->direita == NULL && a->esquerda == NULL) {
        return 1;
    }
    else {
        return folhas(a->esquerda) + folhas(a->direita);
    }
}

int ocorrencias (Arv* a, char c) {
 if(arv_vazia(a)) {
     return 0;
 }
 if(a->info == c) {
     return 1;
 }
 return ocorrencias(a->esquerda, c) + ocorrencias(a->direita, c);
}

char info (Arv* a) {
    if (!arv_vazia(a)) {
        return a->info;
    }

}

int max2(int a, int b) {
    return (a>b) ? a : b;
}
int altura (Arv* a) {
    if(arv_vazia(a)) {
        return -1;
    }
    else {
        return 1 + max2(altura(a->esquerda), altura(a->direita));
    }

}
