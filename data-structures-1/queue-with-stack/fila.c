#include "fila.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
    Pilha* p;
    Pilha* aux;
};

Fila* cria_fila(void) { 
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->p = cria_pilha();
    f->aux = cria_pilha();
    return f;
}

void insere (Pessoa* pessoa, Fila* f) {
    if (tamanho_pilha(f->p) == 10 ) {
        printf("irmão, a fila ta cheia rapaz! \n");
        return;
    }
    else {
        push(pessoa, f->p);
    }
}

Pessoa* retira (Fila* f) {
    if(vazia_pilha(f->p)) {
        printf("Fila vazia \n");
        return NULL;
    }
    while (!vazia_pilha(f->p)) {
        push(pop(f->p), f->aux);
    }
    
    Pessoa* p = pop(f->aux);
    
    while(!vazia_pilha(f->aux)) {
        push(pop(f->aux), f->p);
    } 
    return p;
}


void imprime_fila (Fila* f) {
    if(vazia_pilha(f->p)) {
        printf("ta vazio amigão \n");
        return;
    }
    while (!vazia_pilha(f->p)) {
        push(pop(f->p), f->aux);
    }
    imprime_pilha(f->aux);
    
    while(!vazia_pilha(f->aux)) {
    push(pop(f->aux), f->p);
  }
    printf("\n\n");
}


int Vazia_fila (Fila* f) {
    if (vazia_pilha( f->p) == 1) {
        return 1;
    }
    else {
        return 0;
    }
}


void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores) {
    Pessoa* p;
    while(!Vazia_fila(f)) {
        p = retira(f);
        if(retorna_idade(p)>= 60) {
            insere(p, f_maiores);
        }
        else {
            insere(p, f_menores);
        }
    }
}


Fila* destroi_fila (Fila* f) {
    destroi_pilha(f->p);
    destroi_pilha(f->aux);
    free(f);
    return NULL;
}
