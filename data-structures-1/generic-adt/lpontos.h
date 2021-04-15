//
// Created by 2019202297 on 11/11/19.
//

#ifndef TAD_GENERICA_LPONTOS_H
#define TAD_GENERICA_LPONTOS_H

#include "listaGenerica.h"
#include <stdlib.h>


typedef struct tipoponto TipoPonto;
typedef struct cg CG;
// Callbacks

static int imprime(void* info, void* dado);
static int igualdade(void* info, void* dado);
static int centro_geometrico (void* info, void* dado);
static void libera_ponto(void* info);
void imprime_CG(CG* cg);

TipoPonto* cria_ponto(float x, float y);
ListaGen* insere_ponto(ListaGen* l, TipoPonto* p);
void imprime_pontos(ListaGen* l);
CG* centro_geometrico_lista(ListaGen* l);
int pertence(ListaGen* l, TipoPonto* p);
void libera_lista_pontos(ListaGen* l);
ListaGen* retira_ponto(ListaGen* l, TipoPonto* p);

#endif //TAD_GENERICA_LPONTOS_H
