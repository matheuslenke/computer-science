//
// Created by 2019202297 on 11/11/19.
//

#include "lpontos.h"
#include <stdlib.h>
#include <stdio.h>
struct tipoponto {
    float x, y ;
};

struct cg {
    int n;
    TipoPonto p;
};

// Callbacks

static int imprime(void* info, void* dado) {
    TipoPonto* p = (TipoPonto*) info;
    printf("Ponto: (%f,%f) \n", p->x, p->y);
    return 0;
}
static int igualdade(void* info, void* dado) {
    TipoPonto* p1 = (TipoPonto*) info;
    TipoPonto* p2 = (TipoPonto*) dado;
    if((p1->x == p2->x) && (p1->y == p2->y))
        return 1;
    return 0;
}
static int centro_geometrico (void* info, void* dado) {
    TipoPonto* p = (TipoPonto*)info;
    CG* cg = (CG*)dado;
    cg->p.x += p->x;
    cg->p.y += p->y;
    cg->n++;
    return 0;
}

void imprime_CG(CG* cg) {

    printf("Numero de pontos: %d \n", cg->n);
    void* ponto = (void*)(&cg->p);
    imprime(ponto, NULL);
}

static void libera_ponto(void* info) {
    TipoPonto* p = (TipoPonto*)info;
    free(p);
}


// Funcoes da lista


TipoPonto* cria_ponto(float x, float y) {
    TipoPonto* p = (TipoPonto*) malloc(sizeof(TipoPonto));
    p->x = x;
    p->y = y;
    return p;
}

ListaGen* insere_ponto(ListaGen* l, TipoPonto* p) {
    l = listagen_insere(l,p);
    return l;
}

void imprime_pontos(ListaGen* l) {
    listagen_percorre(l, imprime, NULL);
}

CG* centro_geometrico_lista(ListaGen* l) {
    CG* cg = (CG*)malloc(sizeof(CG));
    cg->p.x = 0;
    cg->p.y = 0;
    listagen_percorre(l, centro_geometrico, cg);
    return cg;
}

int pertence(ListaGen* l, TipoPonto* p) {
    return listagen_percorre(l, igualdade, p);
}

void libera_lista_pontos(ListaGen* l) {
    listagen_libera(l, libera_ponto);
}

ListaGen* retira_ponto(ListaGen* l, TipoPonto* p) {
    if( pertence(l, p)) {
        l = listagen_retira(l, igualdade, libera_ponto, p);
        return l;
    }
}