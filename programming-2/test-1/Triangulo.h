//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_TRIANGULO_H
#define T1_TOPICOS_PROG_TRIANGULO_H

#include <stdio.h>

typedef struct triangulo tTriangulo;

tTriangulo * inicializaTriangulo();
tTriangulo * leTriangulo(FILE *file, tTriangulo *triangulo);

tTriangulo * atualizaTriangulo(FILE *file, tTriangulo *triangulo);

float areaTriangulo(tTriangulo* triangulo);
#endif //T1_TOPICOS_PROG_TRIANGULO_H
