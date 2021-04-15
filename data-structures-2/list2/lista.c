//
// Created by lenke on 24/09/2020.
//

#include <stdio.h>
#include "lista.h"
#include "bst.h"
#include <stdlib.h>
#include <string.h>

typedef struct Celula TipoCelula;
struct tipoitem {
    Arv* arvore
};

struct tipolista {
    TipoCelula* inicio;
    TipoCelula* fim;
};

struct Celula {
    TipoItem* item;
    TipoCelula* prox;
};


TipoLista* InicializaLista ( ) {
    TipoLista* lista;
    lista =(TipoLista*)malloc(sizeof(TipoLista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void Insere (TipoItem* item, TipoLista* lista) {
    TipoCelula* nova = (TipoCelula*)malloc(sizeof(TipoCelula));
    TipoCelula * p, * anterior;
    nova->item = item;
    nova->prox = NULL;
    if ( lista->inicio == NULL) {
        lista->inicio = lista -> fim = nova;
    }
    else {
        lista->fim->prox = nova;

    }
}

Arv* Retira (TipoLista* lista) {
    TipoCelula* anterior, *p;
    Arv* a;
    anterior = NULL;

    if(lista->inicio == NULL) {
        return NULL;
    }

    p = lista->inicio;
    a = p->item->arvore;
    lista->inicio = p->prox;

    return a;
}


void Imprime (TipoLista* lista) {
    for(TipoCelula* p = lista->inicio; p!= NULL; p = p->prox) {
        arv_imprime_item(p->item->arvore);
    }
}

TipoLista* Libera (TipoLista* lista) {
    TipoCelula* aux;
    TipoCelula* p = lista->inicio;
    while ( p!= NULL) {
        aux = p;
        p = p->prox;
        free(aux->prox);
        free(aux);

    }
    lista->inicio = NULL;
    lista->fim = NULL;

}


TipoItem* InicializaTipoItem(Arv* a) {
    TipoItem* item = (TipoItem*)malloc(sizeof(struct tipoitem));
    item->arvore = a;
    return item;
}
