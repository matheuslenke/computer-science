//
// Created by lenke on 24/09/2020.
//

#ifndef EX1_BST_H
#define EX1_BST_H


typedef struct arv Arv;

Arv* arv_criavazia(void);

void arv_imprime(Arv* a);

Arv* arv_insere (int info, Arv* a);

Arv* arv_busca (Arv* a, int info );

Arv* retira(Arv *r, int v);

Arv* arv_libera (Arv* a);

int arv_altura (Arv* a);

void visita_arvore(Arv * a);

void rec_preorder(Arv* a, void (*visita_arvore)(Arv*));

void rec_inorder(Arv* a, void (*visita_arvore)(Arv*));

void rec_postorder(Arv* a, void (*visita_arvore)(Arv*));

void iterative_rec_preorder(Arv* a, void (*visita_arvore)(Arv*));

void iterative_rec_inorder(Arv* a, void (*visita_arvore)(Arv*));

void iterative_rec_postorder(Arv* a, void (*visita_arvore)(Arv*));

int arv_retorna_info(Arv* a);

void print_level_order(Arv* arv);

void arv_imprime_item(Arv* a);

#endif //EX1_BST_H
