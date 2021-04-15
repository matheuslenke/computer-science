#ifndef _CURSOS
    #define _CURSOS
#include <stdio.h>
#include "curso.h"


typedef struct cursos {
    tCurso curso[30];
    int quantidade_cursos;
}tCursos;

void inicializaCodigos(tCursos* cursos);

void lerCodigos(tCursos* cursos, FILE*);

int verificaCurso(tCursos* cursos, int);

void lerCursos(tCursos* cursos, FILE*);

void apresentarCursos(tCursos* cursos);

void ordenaCursos();
#endif