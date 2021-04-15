//
// Created by mathe on 26/10/2019.
//

#include "Trapezio.h"
#include <stdio.h>
#include <stdlib.h>

struct trapezio {
    float base1, base2, altura;
};

tTrapezio * inicializaTrapezio() {
    tTrapezio* trapezio = (tTrapezio*)malloc(sizeof(tTrapezio));
    return trapezio;
}

tTrapezio* leTrapezio(FILE *file, tTrapezio *trapezio) {
    trapezio = inicializaTrapezio();
    fscanf(file," %f %f %f ", &trapezio->base1,
        &trapezio->base2,
        &trapezio->altura);
    return trapezio;
}
tTrapezio* atualizaTrapezio(FILE *file, tTrapezio *trapezio) {
    trapezio = inicializaTrapezio();
    fscanf(file," %f %f %f ", &trapezio->base1,
        &trapezio->base2,
        &trapezio->altura);
    return trapezio;
}

float areaTrapezio(tTrapezio* trapezio) {
    return (float) (((trapezio->base1 + trapezio->base2)* trapezio->altura) /2.0);
}