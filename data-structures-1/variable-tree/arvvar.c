//
// Created by 2019202297 on 18/11/19.
//

#include "arvvar.h"
#include <stdlib.h>

struct arvvar {
    char info;
    ArvVar* prim;
    ArvVar* prox;
};

ArvVar* arvv_cria(char info) {
    ArvVar* a;
    a = (ArvVar*)malloc(sizeof(ArvVar));
    a->info = info;
    a->prox = NULL;
    a->prim = NULL;
    return a;
}

ArvVar* arvv_insere(ArvVar* a, ArvVar* sa) {
    sa->prox = a->prim;
    a->prim = sa;
}


int arvv_pertence(ArvVar* a, char c) {
    ArvVar* p;

    if(a->info == c)
        return 1;

    for (p = a->prim; p != NULL; p = p->prox) {
        if (arvv_pertence(p, c))
            return 1;
    }
}

void arvv_imprime (ArvVar* a) {
    ArvVar* p;
    printf("< %c ",a->info);
    for (p=a->prim; p!=NULL; p=p->prox)
        arvv_imprime(p); /* imprime filhas */
    printf(">");
}

void arvv_libera(ArvVar* a) {
    ArvVar* p = a->prim;

    while ( p!= NULL) {
        ArvVar* t = p->prox;
        arvv_libera(p);
        p = t;
    }
    free(a);
}

int arvv_altura(ArvVar* a) {
    ArvVar* p;
    int hmax = -1;
    for(p = a->prim; p!= NULL; p=p->prox) {
        int h = arvv_altura(p);
        if (h > hmax)
            hmax = h;
    }
    return hmax + 1;
}

int arvv_folhas(ArvVar* a) {
    ArvVar* p;
    int n = 0;
    if (a->prim == NULL) {
        return 1;
    }

    for (p=a->prim; p!=NULL; p=p->prox)
        n += arvv_folhas(p);
    return n;
}