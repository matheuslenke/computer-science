//
// Created by lenke on 04/03/2020.
//

#include "alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct taluno {
    char* nome;
    float nota;
};

tAluno* leAluno(char* nome, float nota) {
    tAluno* aluno;
    aluno = (tAluno*) malloc(sizeof(tAluno));
    aluno->nome = strdup(nome);
    aluno->nota = nota;

    return aluno;
}

void imprimeAluno(tAluno* aluno) {
    printf("O aluno %s tirou a nota %.1f\n", aluno->nome, aluno->nota);
}

char* retornaNome(tAluno* aluno) {
    return aluno->nome;
}

float retornaNota(tAluno* aluno) {
    return aluno->nota;
}

float calculaMedia(tAluno** alunos, int quantidade) {
    float soma = 0;
    float media;
    for (int i = 0; i < quantidade; i ++) {
        soma += alunos[i]->nota;
    }
    media = (float) soma / quantidade;
    return media;
}

int compararAlunos(const void* a, const void* b)
{
    int arg1 = *(const char*)a;
    int arg2 = *(const char*)b;

    if (strcmp(arg1, arg2) < 0) return -1;
    if (strcmp(arg1, arg2) > 0) return 1;
    return 0;
}

void ordenaAlunos(tAluno** alunos,int quantidade) {
    int size = sizeof(tAluno*) / sizeof(alunos[0]);
    qsort((void*)alunos, size , sizeof(alunos[0]), compararAlunos);
}