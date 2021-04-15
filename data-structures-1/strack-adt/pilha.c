#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

#define MAXTAM 10

struct pessoa{
    char* nome;
    int idade;
    char* endereco;
};

struct pilha{
    Pessoa* Pessoas[MAXTAM];
    int topo;
};

Pilha* cria_pilha() {
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = 0;
}

void push(Pessoa* pessoa, Pilha* pilha){
    if(pilha->topo == MAXTAM) {
        return;
    }
    pilha->Pessoas[pilha->topo] = pessoa;
    pilha->topo++;
}

Pessoa* pop(Pilha* pilha){
    if(pilha->topo == 0 ) {
        return NULL;
    }
    Pessoa* p = pilha->Pessoas[pilha->topo-1];
    pilha->topo--;
    return p;
}


void imprime_pilha (Pilha* pilha) {
    for(int i =0; i<pilha->topo; i++) {
       printf("Nome: %s idade: %d Endereço: %s \n",  
       pilha->Pessoas[i]->nome,
       pilha->Pessoas[i]->idade,
       pilha->Pessoas[i]->endereco);
    }
}



Pilha* destroi_pilha(Pilha* pilha){
    for(int i =0; i<pilha->topo; i++) { 
        free(pilha->Pessoas[i]->nome);
        free(pilha->Pessoas[i]->endereco);
        free(pilha->Pessoas[i]);
    }
    free(pilha);
}

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco) {
    Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
    pessoa->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    pessoa->endereco = (char*)malloc((strlen(endereco)+1)*sizeof(char));
    strcpy(pessoa->nome, nome);
    strcpy(pessoa->endereco, endereco);
    pessoa->idade = idade; 
}



