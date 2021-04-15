/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"
#include <string.h>

struct tipoitem {
    char* nome;
    char* end;
    int mat;
};  

struct tipolistadpl{
    TipoItem* item;
    TipoListaDpl* prox;
    TipoListaDpl* ant;
};

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco) {
    TipoItem* item;
    item = (TipoItem*)malloc(sizeof(TipoItem));
    item->nome = (char*)malloc(sizeof( (strlen(nome)+1) * sizeof(char)) );
    item->end = (char*)malloc(sizeof( (strlen(endereco)+1) * sizeof(char)) );

    strcpy(item->nome , nome);
    strcpy(item->end, endereco);
    item->mat = matricula;
    
    return item;
}

TipoListaDpl* Insere (TipoItem* aluno, TipoListaDpl* lista) {
    TipoListaDpl* nova = (TipoListaDpl*)malloc(sizeof(TipoListaDpl));
    nova->item = aluno;
    nova->prox = lista;
    nova->ant = NULL;
    if (lista == NULL) {
        return nova;
    }
    else {
        lista -> ant = nova;
    }
    return nova;
}

TipoListaDpl* Retira (TipoListaDpl* lista, char* nome) {
     TipoListaDpl* p;
     int retirou = 0;
     for(p = lista ; p != NULL && retirou == 0; p = p->prox ) {
        if ( strcmp(p->item->nome, nome) == 0) {
            if(p->ant == NULL && p->prox != NULL){
                p->prox->ant = p->ant;
                retirou = 1;
            }
            if (p->ant != NULL && p->prox == NULL) {
                p->ant->prox = p->prox;
                retirou = 1;
            }
            if (p->ant != NULL && p->prox != NULL){
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                retirou = 1;
            }
            if(retirou == 1) {
                free(p->item->end);
                free(p->item->nome);
                free(p->item);
                free(p);
            }
        }
    }
    return lista;
}

void Imprime (TipoListaDpl* lista) {
    TipoListaDpl* p;
    for(p = lista ; p != NULL; p = p->prox) {
        printf("Aluno: %s |", p->item->nome);
        printf(" Endereco: %s |", p->item->end);
        printf(" Matricula: %d \n", p->item->mat);
    }

}



TipoListaDpl* libera (TipoListaDpl* lista) {
    TipoListaDpl* p;
    for(p = lista ; p != NULL ; p = p->prox ) {
        free(p->item->end);
        free(p->item->nome);
        free(p->item);
        free(p);
    }
    printf("\n A lista foi liberada. \n");
    return lista;
}
