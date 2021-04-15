#include "curso.h"
#include <stdio.h>
#include <stdlib.h>

void lerCurso(tCurso* curso, FILE* file, int codigo_turma) {

    lerTurma(&curso->turma_curso, file, codigo_turma);
    curso->codigocurso = curso->turma_curso.alunos[0].codigocurso;
}

void apresentarCurso(tCurso* curso) {
    printf("Turma do curso: %d \n", curso->codigocurso );
    printf("ta entrando aq ");
    apresentarTurma(&curso->turma_curso);
}

void ordenaCurso() {

}