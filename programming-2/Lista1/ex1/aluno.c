#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void lerAluno(tAluno* aluno, FILE *file) {
    fscanf(file, "%d %d %f", &aluno->codigocurso, &aluno->matricula, &aluno->coeficiente);

}

void apresentarAluno(tAluno* aluno) {
    printf("Aluno \n Código do curso: %d Matrícula: %d CR: %f \n", aluno->codigocurso, aluno->matricula, aluno->coeficiente);
}

int comparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    if(aluno1->matricula > aluno2->matricula) {
        return 1;
    }
    if(aluno1->matricula == aluno2->matricula) {
        return 0;
    }
    if (aluno1->matricula < aluno2->matricula) {
        return -1;
    }
}