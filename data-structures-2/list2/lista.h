//
// Created by lenke on 24/09/2020.
//

#ifndef EX1_LISTA_H
#define EX1_LISTA_H
#include "bst.h"

typedef struct tipoitem TipoItem;

typedef struct tipolista TipoLista;

TipoLista* InicializaLista();

void Insere (TipoItem* item, TipoLista* lista);

Arv* Retira (TipoLista* lista);

void Imprime (TipoLista* lista);

TipoLista* Libera (TipoLista* lista);

TipoItem* InicializaTipoItem(Arv* a);


#endif //EX1_LISTA_H
