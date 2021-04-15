//
// Created by lenke on 24/09/2020.
//

#ifndef EX1_PILHA_H
#define EX1_PILHA_H
#include "bst.h"

typedef struct pilha Pilha;

Pilha* cria_pilha();

void push(Arv *arvore, Pilha* pilha);

Arv * pop(Pilha* pilha);

void imprime_pilha (Pilha* pilha);

Pilha* destroi_pilha(Pilha* pilha);

int eh_vazia(Pilha* pilha);

Arv* peek(Pilha* pilha);

#endif //EX1_PILHA_H
