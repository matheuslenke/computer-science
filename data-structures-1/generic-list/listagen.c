//
// Created by Matheus Lenke on 08/12/19.
//

#include "listagen.h"

struct listagen {
    tCelulagen* inicio;
    tCelulagen* fim;
};

struct celulagen {
    void* info;
    tCelulagen* prox;
};

ListaGen* listagen_insere(ListaGen* l, void* p) {
    // Se for nula, inicializa a lista
    if(l == NULL) {
        l = (ListaGen*) malloc(sizeof(ListaGen));
        tCelulagen* nova = (tCelulagen*)malloc(sizeof(tCelulagen));
        nova->info = p;
        nova->prox = NULL;
        l->inicio = l->fim = nova;
        return l;
    }
    // Se não for, insere no final
    else {
        tCelulagen* nova = (tCelulagen*)malloc(sizeof(tCelulagen));
        nova->info = p;
        nova->prox = l->fim->prox;
        l->fim->prox = nova;
        l->fim = nova;
        return l;
    }
}

int listagen_percorre(ListaGen* l, int(*cb)(void*, void*), void* dado) {
    tCelulagen* p;
    for(p = l->inicio; p != NULL; p = p->prox) {
        int r = cb(p->info, dado);
        if(r != 0) {
            return r;
        }
    }
    return 0;
}
// Funcao 1 verifica se eh o elemento e a 2 libera
ListaGen* listagen_retira(ListaGen* l, int(*cb)(void*, void*), void(*cb2)(void*), void* dado) {
    tCelulagen* p;
    tCelulagen* ant = l->inicio;
    for(p = l->inicio; p != NULL; p = p->prox) {
        if((cb(p->info, dado)) == 1 && p == l->inicio) {
            l->inicio = p->prox;
            cb2(p->info);
            free(p);
            return l;
        }
        if((cb(p->info, dado)) == 1 && p != l->inicio) {
            ant->prox = p->prox;
            cb2(p->info);
            free(p);
            return l;
        }
        ant = p;
    }
}

void listagen_libera(ListaGen* l, void(*cb)(void*)) {
    tCelulagen* p, *aux;
    p = l->inicio;
    while (p!= NULL) {
        aux = p;
        p = p->prox;
        cb(aux->info);
        free(aux);
    }
    free(l);
}
