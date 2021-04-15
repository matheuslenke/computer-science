//
// Created by 2019202297 on 04/11/19.
//

#ifndef ARVORE_BUSCA_ABB_H
#define ARVORE_BUSCA_ABB_H

typedef struct arv Arv;

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

Arv* arv_insere (int info, Arv* a);

Arv* arv_busca (Arv* a, int info );

Arv* retira(Arv *r, int v);

Arv* arv_libera (Arv* a);
#endif //ARVORE_BUSCA_ABB_H
