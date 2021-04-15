//
// Created by lenke on 02/11/2020.
//

#ifndef LISTA6_PILHA_H
#define LISTA6_PILHA_H

#include "item.h"

typedef struct pessoa Pessoa;

typedef struct pilha Pilha;

Pilha* cria_pilha();

void push(Item* item, Pilha* pilha);

Item* pop(Pilha* pilha);

Pilha* destroi_pilha(Pilha* pilha);

int pilha_vazia(Pilha* pilha);

#endif //LISTA6_PILHA_H
