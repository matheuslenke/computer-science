//
// Created by lenke on 21/09/2020.
//

#include "pilha.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTAM 100

struct item {
  void* dado;
};

struct pilha{
    Item* Items[MAXTAM];
    int topo;
};

Pilha* cria_pilha() {
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = 0;
}

void push(Item* item, Pilha* pilha){
    if(pilha->topo == MAXTAM) {
        return;
    }
    pilha->Items[pilha->topo] = item;
    pilha->topo++;
}

void* pop(Pilha* pilha){
    if(pilha->topo == 0 ) {
        return NULL;
    }
    Item* p = pilha->Items[pilha->topo-1];
    pilha->topo--;
    return p->dado;
}


void imprime_pilha (Pilha* pilha) {
    for(int i =0; i<pilha->topo; i++) {
        char imprimir = *(char*) pilha->Items[i]->dado;
        printf("Dado: %c\n", imprimir);
    }
}

Pilha* destroi_pilha(Pilha* pilha){
    for(int i =0; i<pilha->topo; i++) {
        free(pilha->Items[i]->dado);
    }
    free(pilha);
}

Item *inicializaItem(void *dado) {
     return dado;
}

