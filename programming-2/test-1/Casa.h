//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_CASA_H
#define T1_TOPICOS_PROG_CASA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tipocasa tCasa;

tCasa * inicializaCasa();

int retornaQuartos(tCasa *casa);

tCasa* leCasa(FILE* file, tCasa *casa);

tCasa* atualizaCasa (FILE* file, tCasa *casa);

float calculaPrecoCasa(tCasa *casa);

float retornaArea(tCasa *casa);

void liberaCasa(tCasa* casa);

#endif //T1_TOPICOS_PROG_CASA_H
