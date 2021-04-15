//
// Created by lenke on 21/09/2020.
//

#ifndef EX3_PILHA_H
#define EX3_PILHA_H

typedef struct item Item;

typedef struct pilha Pilha;

Pilha* cria_pilha();

void push(Item* item, Pilha* pilha);

void* pop(Pilha* pilha);

void imprime_pilha (Pilha* pilha);

Pilha* destroi_pilha(Pilha* pilha);

Item* inicializaItem(void* dado);

#endif //EX3_PILHA_H
