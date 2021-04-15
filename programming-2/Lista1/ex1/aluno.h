#ifndef _ALUNO
#define _ALUNO

#include <stdio.h>

typedef struct aluno {
    int codigocurso;
    int matricula;
    float coeficiente;

} tAluno;

void lerAluno(tAluno*, FILE *file);

void apresentarAluno(tAluno*);

/* Aponta para o aluno de menor matrícula
*/
int comparaMatricula(tAluno*, tAluno*);


#endif