#include "turma.h"
#include <stdio.h>
#include <stdlib.h>

void lerTurma(tTurma* turma, FILE* file, int codigo_turma) {
    int i = 0; 
    do {
        lerAluno(&turma->alunos[i], file);
        if(turma->alunos[i].codigocurso == codigo_turma ) {
        turma->quantidade_alunos++;
        apresentarAluno(&turma->alunos[i]);
        }
        else {
            i--;
        }
        i++;
    } while(!feof(file) && turma->quantidade_alunos<100);
    return;
}


void apresentarTurma(tTurma* turma) {
    for (int i = 0; i<turma->quantidade_alunos; i++) {
        printf("ta entrando aq");
        apresentarAluno(&turma->alunos[i]);
    }
}

void ordernaTurma(tTurma* turma, int (*f)(tAluno*, tAluno*)) {
    tAluno auxiliar;
    for(int i = 0; i<turma->quantidade_alunos ; i++) {
        for(int j = i; j< turma->quantidade_alunos; j++) {
            if((*f)(&turma->alunos[i], &turma->alunos[j]) == 1 ) {
                auxiliar = turma->alunos[i];
                turma->alunos[i] = turma->alunos[j];
                turma->alunos[j] = auxiliar;
            }
        }
    }
}
