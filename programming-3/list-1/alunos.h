//
// Created by lenke on 04/03/2020.
//

#ifndef LISTA1_ALUNOS_H
#define LISTA1_ALUNOS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct taluno tAluno;

tAluno* leAluno(char* nome, float nota);

void imprimeAluno(tAluno* aluno);

char* retornaNome(tAluno* aluno);

float retornaNota(tAluno* aluno);

float calculaMedia(tAluno** alunos, int quantidade);

int compararAlunos(const void* a, const void* b);

void ordenaAlunos(tAluno** alunos, int quantidade);


#endif //LISTA1_ALUNOS_H
