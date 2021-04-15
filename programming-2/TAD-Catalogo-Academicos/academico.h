//
// Created by 2019202297 on 31/10/19.
//

#ifndef TAD_CATALOGO_ACADEMICOS_ACADEMICOS_H
#define TAD_CATALOGO_ACADEMICOS_ACADEMICOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct academico tAcademico;

tAcademico* leAcademico(FILE* file);

tAcademico* InicializaAcademico(char* nome, unsigned int idade, unsigned int matricula);

int compMatricula(tAcademico* p, tAcademico* s);

int compIdade(tAcademico* p, tAcademico* s);

int compNome(tAcademico* p, tAcademico* s);

void apresentaAcademico(tAcademico* academico);

#endif //TAD_CATALOGO_ACADEMICOS_ACADEMICOS_H
