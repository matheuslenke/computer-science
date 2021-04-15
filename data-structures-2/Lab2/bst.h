#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

typedef struct arv Arv;

Arv* arv_criavazia(void);

void arv_imprime(Arv* a);

Arv* arv_insere (int info, Arv* a);

Arv* arv_busca (Arv* a, int info );

Arv* retira(Arv *r, int v);

Arv* arv_libera (Arv* a);

int arv_altura (Arv* a);

#endif //ARVORE_BINARIA_BUSCA_H