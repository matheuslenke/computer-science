#ifndef _CURSO
    #define _CURSO
#include <stdio.h>
#include "turma.h"


typedef struct curso {
    int codigocurso;
    tTurma turma_curso;
}tCurso;


void lerCurso(tCurso* curso, FILE*, int);

void apresentarCurso(tCurso* curso);

void ordenaCurso();
#endif