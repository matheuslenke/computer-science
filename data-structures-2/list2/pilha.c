//
// Created by lenke on 24/09/2020.
//

#include "pilha.h"
#include <stdlib.h>

#define MAXTAM 100

struct pilha{
    Arv* Arvores[MAXTAM];
    int topo;
};

Pilha* cria_pilha() {
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = 0;
}

void push(Arv *arvore, Pilha* pilha){
    if(pilha->topo == MAXTAM) {
        return;
    }
    pilha->Arvores[pilha->topo] = arvore;
    pilha->topo++;
}

Arv * pop(Pilha* pilha){
    if(pilha->topo == 0 ) {
        return NULL;
    }
    Arv* p = pilha->Arvores[pilha->topo-1];
    pilha->topo--;
    return p;
}

void imprime_pilha (Pilha* pilha) {
    for(int i =0; i<pilha->topo; i++) {
        arv_imprime(pilha->Arvores[i]);
    }
}

Pilha* destroi_pilha(Pilha* pilha){
    for(int i =0; i<pilha->topo; i++) {
        free(pilha->Arvores[i]);
    }
    free(pilha);
}

int eh_vazia(Pilha* pilha) {
    if(pilha->topo == 0) {
        return 1;
    }
    else return -1;
}

Arv* peek(Pilha* pilha) {
    return pilha->Arvores[pilha->topo - 1];
}
