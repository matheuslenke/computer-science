#include <stdio.h>
#include "lista.h"

typedef struct Celula TipoCelula;

struct Aluno {
    char nome;
    int matricula;
};

//Sentinela
struct Lista {
    TipoCelula* inicio;
    TipoCelula* fim;
};

struct Celula {
    TAluno* aluno;
    TipoCelula* prox;
} tCelula;

TLista* InicializaLista() {
    TLista* lista;
    lista = (Tlista*)malloc(sizeof(Tlista));
    lista->inicio
}

TAluno* InicializaAluno(char* nome, int matricula) {

}

void Insere (TAluno* aluno, TLista* lista) {

}

TAluno* Retira (TLista* lista, int mat) {

}

void RetiraRepetidos (TLista* lista) {

}

void LiberaAluno (TAluno* aluno) {

}


void Imprime (TLista* lista) {

}

void Libera (TLista* lista) {

}
