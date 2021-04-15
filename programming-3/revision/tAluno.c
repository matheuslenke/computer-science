//
// Created by lenke on 14/09/2020.
//

#include "tAluno.h"
#include <string.h>
#include <stdlib.h>

struct TAluno {
    char nome[50];
    float nota;
};

tAluno criarAluno (char* nome, float nota ) {
    tAluno aluno = (tAluno)malloc(sizeof(struct TAluno));
    strcpy(aluno->nome, nome);
    aluno->nota = nota;
    return aluno;
}

char * obterNomeAluno(tAluno aluno) {
    return aluno->nome;
}

float obterNotaAluno(tAluno aluno) {
    return aluno->nota;
}

void destruirAluno(tAluno aluno) {
    free(aluno);
}

int comparaPorNomeAluno(const void* p1, const void* p2) {
    tAluno a1 = *(tAluno*)p1;
    tAluno a2 = *(tAluno*)p2;

    return strcmp(a1->nome, a2->nome);

}