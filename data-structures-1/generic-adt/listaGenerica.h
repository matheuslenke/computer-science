//
// Created by 2019202297 on 11/11/19.
//

#ifndef TAD_GENERICA_LISTAGENERICA_H
#define TAD_GENERICA_LISTAGENERICA_H

typedef struct listagen ListaGen;




ListaGen* listagen_insere(ListaGen* l, void* p);

int  listagen_percorre(ListaGen* l, int(*cb)(void*, void*), void* dado);

void listagen_libera(ListaGen* l, void(*cb)(void*));

/**
 *
 * @param l lista generica
 * @param cb Callback de igualdade
 * @param cb2 Callback de libera
 * @param dado a ser removido
 */
ListaGen* listagen_retira(ListaGen* l, int(*cb)(void*, void*), void(*cb2)(void*), void* dado);

#endif //TAD_GENERICA_LISTAGENERICA_H
