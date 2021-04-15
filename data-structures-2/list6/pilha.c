#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"
#include "item.h"

#define MAXTAM 1000


struct pilha{
    Item* items;
    int topo;
};

Pilha* cria_pilha(int tamanho) {
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->items = (Item*)malloc((tamanho + 1) * sizeof(Item));
    pilha->topo = 0;
}

void push(Item* item, Pilha* pilha){
    if(pilha->topo == MAXTAM) {
        return;
    }
    pilha->items[pilha->topo] = item;
    pilha->topo++;
}

Item* pop(Pilha* pilha) {
    if(pilha->topo == 0 ) {
        return NULL;
    }
    Item* a = pilha->items[pilha->topo-1];
    pilha->topo--;
    return a;
}

Pilha* destroi_pilha(Pilha* pilha){
    free(pilha);
}


int pilha_vazia(Pilha* pilha) {
    if(pilha->topo <= 0) {
        return 1;
    }
    return 0;
}

