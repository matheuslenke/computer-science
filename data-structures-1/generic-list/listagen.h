//
// Created by Matheus Lenke on 08/12/19.
//

#ifndef PROVA1_LISTAGEN_H
#define PROVA1_LISTAGEN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct listagen ListaGen;

typedef struct celulagen tCelulagen;

ListaGen* listagen_insere(ListaGen* l, void* p);

int listagen_percorre(ListaGen* l, int(*cb)(void*, void*), void* dado);

ListaGen* listagen_retira(ListaGen* l, int(*cb)(void*, void*), void(*cb2)(void*), void* dado);

void listagen_libera(ListaGen* l, void(*cb)(void*));
#endif //PROVA1_LISTAGEN_H
