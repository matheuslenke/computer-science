//Aluno library
#ifndef _ALUNO
#define _ALUNO
#include "data.h"

typedef struct tAluno {
    char nome[20];
    char matricula[10];
    int idade;
    float cr;
    tData data_ingresso;
    tData data_nascimento;
} tAluno;

void lerAluno(tAluno*, FILE*);

void apresentarAluno(tAluno*);

void compararNome(tAluno*, tAluno*);

void compararIngresso(tAluno*, tAluno*);

void compararMatricula(tAluno*, tAluno*);

void compararCR(tAluno*, tAluno*);

void ehAniversario(tAluno*, tData);

void ehExcelente(tAluno*);

#endif