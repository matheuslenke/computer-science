

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    Arv* dir;
    Arv* esq;
};

Arv* arv_criavazia(void) {
    Arv* a;
    a = (Arv*)malloc(sizeof(Arv));
    a->info = (int) NULL;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

int arv_vazia (Arv* a) {
    return (a==NULL) ? 1 : 0;
}

void arv_imprime(Arv* a) {
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

Arv* arv_insere (int info, Arv* a) {
    if(a == NULL) {
        a = arv_criavazia();
        a->info = info;
        return a;
    }

    if(info < a->info) {
        a->esq = arv_insere(info, a->esq);
        return a;
    }
    if(info > a->info) {
        a->dir = arv_insere(info, a->dir);
        return a;
    }
    if(info == a->info) {
        // printf("Não é possível inserir um valor igual\n");
        return a;
    }
}

Arv* arv_busca (Arv* a, int info ) {

}

Arv* retira(Arv *r, int v) {

}

int max2(int a, int b) {
    return (a>b) ? a : b;
}
int arv_altura (Arv* a) {
    if(arv_vazia(a)) {
        return -1;
    }
    else {
        return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));
    }

}

Arv* arv_libera (Arv* a) {
    if(a == NULL || (a->info ==  NULL && a->dir == NULL && a->esq == NULL)) {
        return NULL;
    }

    if(a->esq == NULL && a->dir == NULL) {
        free(a);
    }
    else {
        arv_libera(a->esq);
        arv_libera(a->dir);
        
    }
    return a;
}