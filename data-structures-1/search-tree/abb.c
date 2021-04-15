//
// Created by 2019202297 on 04/11/19.
//

#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    Arv* dir;
    Arv* esq;
};

Arv* arv_criavazia (){
    Arv* a;
    a = (Arv*)malloc(sizeof(Arv));
    a->info = (int) NULL;
    a->esq = NULL;
    a->dir = NULL;
    return a;
}


void arv_imprime (Arv* a){
    printf("<");
    if (a != NULL) {
        if(a->esq != NULL) {
            arv_imprime(a->esq);
        }
        else {
            printf(" - ");
        }
        printf(" %d ", a->info);
        if(a->dir != NULL) {
            arv_imprime(a->dir);
        }
        else {
            printf(" - ");
        }
    }
    printf(">");
}

Arv* arv_insere (int info, Arv* a){
    if(a == NULL) {
        a = arv_criavazia();
        a->info = info;
        return a;

    }
    else {
        if(info <= a->info) {
            a->esq = arv_insere(info, a->esq);
            return a;
        }
        if(info >= a->info) {
            a->dir = arv_insere(info, a->dir);
            return a;
        }
    }



}

Arv* arv_busca (Arv* a, int info ){
    if(a == NULL) {
        return NULL;
    }
    else if(a->info == info) {
        return a;
    }
    else if (a->esq != NULL) {
        return arv_busca(a->esq, info);
    }
    else if (a->dir != NULL) {
        return arv_busca(a->dir, info);
    }

    return NULL;
}

Arv* retira(Arv *r, int v){
    if (r == NULL) {
        return NULL;
    }
    if (r->info < v) {
        r->dir = retira(r->dir, v);
    }
    else if(r->info > v) {
        r->esq = retira(r->esq, v);
    }
    else {
        // achei
        if(r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        }
        if(r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        else { // Tem os 2 filhos
            Arv* f = r->esq;
            while(f->dir != NULL) {
                f = f->dir;
            }
            r->info = f->info;
            f->info = v;
            r->esq = retira(r->esq, v);
        }
    }
    return r;
}

Arv* arv_libera (Arv* a) {
    if(a == NULL || (a->info == NULL && a->dir == NULL && a->esq == NULL)) {
        return NULL;
    }
    if(a->esq == NULL && a->dir == NULL) {
        free(a);
    }
    else{
        arv_libera(a->esq);
        arv_libera(a->dir);
    }
    return a;
}