//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_TERRENO_H
#define T1_TOPICOS_PROG_TERRENO_H

#include "Triangulo.h"
#include "Retangulo.h"
#include "Trapezio.h"
#include <stdio.h>

typedef union formato tFormato;

typedef struct tipoterreno tTerreno;

tTerreno* leTerreno(FILE* file, tTerreno *terreno, char* categoria);

tTerreno* atualizaTerreno(FILE* file, tTerreno* terreno, char* categoria);

float calculaPrecoTerreno(tTerreno *terreno);

int ehArgiloso(tTerreno *terreno);

int comparaAreaTerreno(tTerreno *terreno1, tTerreno *terreno2);

void liberaTerreno(tTerreno* terreno);


#endif //T1_TOPICOS_PROG_TERRENO_H
