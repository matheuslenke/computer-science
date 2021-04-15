//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_TRAPEZIO_H
#define T1_TOPICOS_PROG_TRAPEZIO_H

#include <stdio.h>
typedef struct trapezio tTrapezio;

tTrapezio * inicializaTrapezio();

tTrapezio* leTrapezio(FILE *file, tTrapezio *trapezio);

tTrapezio* atualizaTrapezio(FILE *file, tTrapezio *trapezio);

float areaTrapezio(tTrapezio* trapezio);

#endif //T1_TOPICOS_PROG_TRAPEZIO_H
