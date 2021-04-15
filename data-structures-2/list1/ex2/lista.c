//
// Created by lenke on 21/09/2020.
//

#include <stdio.h>
#include "lista.h"
#include <stdlib.h>
#include <string.h>

struct tipoitem {
    int numero;
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

void Insere (TipoItem* pessoa, TipoLista* lista) {
    TipoCelula* nova = (TipoCelula*)malloc(sizeof(TipoCelula));
    nova->item = pessoa;
    nova->prox = nova;
    if ( lista->inicio == NULL) {
        lista->inicio = lista->fim = nova;
    }
    else {
        nova->prox = lista->inicio;
        lista->inicio = nova;
        lista->fim->prox = nova;

    }
    free(nova->item);
    free(nova);
}

int RetornaTamanhoLista(TipoLista* lista) {
    int i = 0;
    for(TipoCelula* p = lista->inicio; p->prox!= lista->inicio; p = p->prox) {
       i++;
    }
    return i;
}

void EncontraSobrevivente (TipoLista* lista, int numero) {
    TipoCelula *p1, *p2;
    p1 = lista->inicio;
    p2 = lista->inicio;
    if(numero == 1) {
        while(p1->prox != p1) {

            p2 = p1;
            p1 = p1->prox;

            p2->prox = p1->prox;
            printf("%d eliminado\n", p1->item->numero);
            free(p1->item);
            free(p1);
            p1 = p2->prox;
        }
        printf("Lider: %d\n", p1->item->numero);
        return;
    }

    while(p1->prox != p1) {

        int count = 1;
        while(count != numero) {
            p2 = p1;
            p1 = p1->prox;
            count++;
        }
            p2->prox = p1->prox;
        printf("%d eliminado\n", p1->item->numero);
        free(p1->item);
        free(p1);
        p1 = p2->prox;
    }
    printf("Lider: %d\n", p1->item->numero);

}


void Imprime (TipoLista* lista) {
    for(TipoCelula* p = lista->inicio; p->prox != lista->inicio; p = p->prox) {
        printf("pessoa retirada: %d\n", p->item->numero);
    }
}



TipoLista* Libera (TipoLista* lista) {
    TipoCelula* aux;
    TipoCelula* p = lista->inicio;
    while ( p!= lista->inicio) {
        aux = p;
        p = p->prox;
        free(aux->prox->item);
        free(aux->prox);
        free(aux->item);
        free(aux);

    }
    lista->inicio = NULL;
    lista->fim = NULL;
    free(lista);

    return NULL;
}

TipoItem *InicializaTipoItem(int numero) {
    TipoItem* pessoa = (TipoItem*)malloc(sizeof(TipoItem));
    pessoa->numero = numero;
    return pessoa;
}