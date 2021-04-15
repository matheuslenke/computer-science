//
// Created by Matheus Lenke on 08/12/19.
//

#include "Arv_exp_gen.h"
#include "arv_gen.h"
#include <stdio.h>
#include <stdlib.h>
typedef union item{
    float operando;
    char operador;
} uItem;

struct arv{
    uItem* item;
    Arv* esq;
    Arv* dir;
};

ArvGen * CriaVazia(){
    return NULL;
}

ArvGen * CriaOperador(char c, Arv* esq, Arv* dir){

    Arv* new = (Arv*)malloc(sizeof(Arv));
    new->item = (uItem*)malloc(sizeof(uItem));
    new->item->operador = c;
    new->dir = dir;
    new->esq = esq;

    ArvGen* arv = arv_cria((void*)new->item,new->dir,  new->esq);
    return arv;
}

ArvGen * CriaOperando(int valor){

    Arv* new = (Arv*)malloc(sizeof(Arv));
    new->item = (union item*)malloc(sizeof(union item));
    new->item->operando = valor;
    new->dir = CriaVazia();
    new->esq = CriaVazia();

    ArvGen* arv = arv_cria((void*)new->item,new->dir, new->esq);
    return arv;
}



static int Imprime (void* info, void* dado) {
    Arv *arv = (Arv *) info;
    if (arv) {
        if (arv->esq || arv->dir)
            printf("<%c", arv->item->operador);
        else
            printf("<%f", arv->item->operando);
        if (arv->esq)
            Imprime(arv->esq, dado);
        if (arv->dir)
            Imprime(arv->dir, dado);
        printf(">");
        return 0;
    }
}
void arv_imprimeArvore(ArvGen* arv) {
    percorre(arv, Imprime, NULL);
}