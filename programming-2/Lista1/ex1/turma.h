#ifndef _TURMA
#define _TURMA

#include "aluno.h"
#include <stdio.h>

typedef struct turma {
    tAluno alunos[100];
    int quantidade_alunos;
} tTurma;


void lerTurma(tTurma* turma, FILE*, int);

void apresentarTurma(tTurma* turma);

void ordernaTurma (tTurma* turma, int (*)(tAluno *, tAluno *));


#endif