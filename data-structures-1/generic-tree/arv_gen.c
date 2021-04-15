//
// Created by Matheus Lenke on 08/12/19.
//

#include "arv_gen.h"
#include <stdlib.h>
#include <stdio.h>

struct arvgen{
    void* info;
    ArvGen* esq;
    ArvGen* dir;
};

ArvGen* arv_CriaVazia() {
    return NULL;
}

ArvGen* arv_cria(void* info, ArvGen* dir, ArvGen* esq) {
    ArvGen* nova = (ArvGen*)malloc(sizeof(ArvGen));

    nova->info = info;
    nova->dir = dir;
    nova->esq = esq;
    return nova;

}

int percorre(ArvGen* arv, int (*cb)(void*, void*), void* dado) {

    int r = cb(arv->info, dado);
    if (r!= 0) {
        return r;
    }

    percorre(arv->esq, cb , dado);

    percorre(arv->dir, cb , dado);

    return 0;
}
