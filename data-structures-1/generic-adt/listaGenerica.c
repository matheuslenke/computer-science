//
// Created by 2019202297 on 11/11/19.
//

#include "listaGenerica.h"
#include <stdio.h>
#include <stdlib.h>
struct listagen {
    void* info;
    ListaGen* prox;
};

ListaGen* listagen_insere(ListaGen* l, void* p) {
    if(l == NULL) {
        l = (ListaGen*)malloc(sizeof(ListaGen));
        l->info = p;
        return l;
    }

    else {
        ListaGen* aux;
        aux = (ListaGen*)malloc(sizeof(ListaGen));
        aux->info = p;
        aux->prox = l;
        l = aux;
        return l;
    }
}

int  listagen_percorre(ListaGen* l, int(*cb)(void*, void*), void* dado) {
    ListaGen* p;
    for (p=l; p!=NULL; p=p->prox) {
        int r = cb(p->info, dado);
        if (r != 0)
            return r;
    }
    return 0;
}

void listagen_libera(ListaGen* l, void(*cb)(void*)) {
    ListaGen* p, *aux;
    p = l;
    while( p!= NULL ) {
        aux = p;
        p = p->prox;
        cb(aux->info);
        free(aux);
    }
}

ListaGen* listagen_retira(ListaGen* l, int(*cb)(void*, void*), void(*cb2)(void*), void* dado) {
    ListaGen* p;
    ListaGen* ant = l;
    for (p=l; p!=NULL; p=p->prox) {
        if((cb(p->info, dado)) == 1 && p == l) {
            l = p->prox;
            cb2(p->info);
            free(p);
            return l;
        }
        if((cb(p->info, dado)) == 1 && p != l) {
            ant->prox = p->prox;
            cb2(p->info);
            free(p);
            return l;
        }
        ant = p;
    }
}