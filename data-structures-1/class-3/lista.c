#include <stdio.h>
#include "lista.h"
#include <stdlib.h>
#include <string.h>

typedef struct Celula TipoCelula;
struct tipoitem {
    char* nome;
    int matricula;
    char* endereco;
};

struct tipolista {
    TipoCelula* inicio;
    TipoCelula* fim;
};

struct Celula {
    TipoItem* item;
    TipoCelula* prox;
};


TipoLista* InicializaLista ( ) {
    TipoLista* lista;
    lista =(TipoLista*)malloc(sizeof(TipoLista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void Insere (TipoItem* aluno, TipoLista* lista) {
    TipoCelula* nova = (TipoCelula*)malloc(sizeof(TipoCelula));
    nova->item = aluno;
    nova->prox = NULL;
    if ( lista->inicio == NULL) {
        lista->inicio = lista -> fim = nova;
    }
    else {
    nova->prox = lista->inicio;
    lista->inicio = nova; 

    }
}

TipoItem* Retira (TipoLista* lista, int mat) {
    TipoItem* auxiliar;
    TipoCelula* anterior, *p;
    anterior = NULL;

     for(p = lista->inicio ; p!= NULL && p->item->matricula != mat; p = p->prox) {
            anterior = p;

     }

        if (p->item->matricula == mat && p != NULL ) {
            anterior->prox = p->prox;
            if ( p ==lista->fim) {
                lista->fim = anterior; 
                 auxiliar = p->item;
 
            }
            if ( anterior == NULL) {
                lista->inicio = p->prox;
                auxiliar = p->item;
            }

            auxiliar = p->item;
            free(p);

            return auxiliar;
            }
        else {
            auxiliar = NULL;
            return auxiliar;
        }
}


void Imprime (TipoLista* lista) {
    for(TipoCelula* p = lista->inicio; p!= NULL; p = p->prox) {
        printf("nome: %s matricula: %d endereco: %s \n", p->item->nome,p->item->matricula,
        p->item->endereco);
    }
}

TipoLista* Libera (TipoLista* lista) {
    TipoCelula* aux;
    TipoCelula* p = lista->inicio;
     while ( p!= NULL) {
         aux = p;
         p = p->prox;
        free(aux->item->nome);
        free(aux->item->endereco);
        free(aux->prox);
        free(aux);
        
    }
    lista->inicio = NULL;
    lista->fim = NULL;

}

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco) {
    TipoItem* aluno = (TipoItem*)malloc(sizeof(TipoItem));
    aluno->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    aluno->endereco = (char*)malloc((strlen(endereco)+1)*sizeof(char));
    strcpy(aluno->nome, nome);
    strcpy(aluno->endereco, endereco);
    aluno->matricula = matricula;
    return aluno;
}


