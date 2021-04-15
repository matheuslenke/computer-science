//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_RETANGULO_H
#define T1_TOPICOS_PROG_RETANGULO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct retangulo tRetangulo;

tRetangulo* inicializaRetangulo();

tRetangulo* leRetangulo(FILE *file, tRetangulo *retangulo);

tRetangulo* atualizaRetangulo(FILE *file, tRetangulo* retangulo);

float areaRetangulo(tRetangulo *retangulo);
#endif //T1_TOPICOS_PROG_RETANGULO_H
