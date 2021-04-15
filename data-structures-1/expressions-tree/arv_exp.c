#include "arv_exp.h"

#include <stdio.h>
#include <stdlib.h>

struct arv{
    char operador;
    int operando;
    Arv* dir;
    Arv* esq;
};


Arv* CriaVazia(void){
    return NULL;
}


Arv* CriaOperador(char c, Arv* esq, Arv* dir){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->operador = c;
    a->dir = dir;
    a->esq = esq;
    return a;
}


Arv* CriaOperando(int valor){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->operando = valor;
}


void Imprime(Arv* arv){
    if(arv->esq != NULL) {
        Imprime(arv->esq);
    }
    if(arv->esq != NULL || arv->dir != NULL) {
        printf( "%c",arv->operador);
    }
    if(arv->esq == NULL || arv->dir == NULL) {
        printf("%d", arv->operando);
    }
    if(arv->dir != NULL) {
       Imprime(arv->dir);
    }
}


Arv* Libera (Arv* arv){

}



float Avalia(Arv* arv){
    if(arv->esq == NULL || arv->dir == NULL) {

    }
}



int Folhas(Arv* arv){

}


int Altura(Arv* arv){

}