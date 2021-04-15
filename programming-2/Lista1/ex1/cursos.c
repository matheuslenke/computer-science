#include "cursos.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaCodigos(tCursos* cursos) {
    for (int i=0; i<30; i++) {
        cursos->curso[i].codigocurso = -1;
    }
    cursos->quantidade_cursos = 0;
}
int verificaCurso(tCursos* cursos, int codigo_curso) {
    int existe = 0;
    for(int i = 0; i<cursos->quantidade_cursos && i<30; i++) {
        if(codigo_curso == cursos->curso[i].codigocurso) {
            existe = 1;
        }
    }
    return existe;
}
void lerCodigos(tCursos* cursos, FILE* file) {
    tAluno auxiliar;
    inicializaCodigos(cursos);
    int i = 0;
    do {
        lerAluno(&auxiliar, file);
        if (verificaCurso(cursos, auxiliar.codigocurso) == 0) {
            cursos->curso[i].codigocurso = auxiliar.codigocurso;
            cursos->quantidade_cursos++;
            i++;
        }
    } while (!feof(file));
}

void lerCursos(tCursos* cursos, FILE* file) {

    for (int i = 0; i < cursos->quantidade_cursos; i++) {
        lerTurma(&cursos->curso[i].turma_curso, file, cursos->curso[i].codigocurso);
    }
}

void apresentarCursos(tCursos* cursos) {
    for (int i = 0 ; i<cursos->quantidade_cursos; i++) {
        apresentarCurso(&cursos->curso[i]);
    }
}

void ordenaCursos();