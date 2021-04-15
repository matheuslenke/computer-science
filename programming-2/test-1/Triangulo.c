//
// Created by mathe on 26/10/2019.
//

#include "Triangulo.h"
#include <stdio.h>
#include <stdlib.h>

struct triangulo {
    float base;
    float altura;
};

tTriangulo* inicializaTriangulo() {
    tTriangulo* triangulo = (tTriangulo*) malloc(sizeof(tTriangulo));
    return triangulo;
}

tTriangulo * leTriangulo(FILE *file, tTriangulo *triangulo) {

    triangulo = inicializaTriangulo();
    fscanf(file," %f %f ", &triangulo->base,
            &triangulo->altura);
    return triangulo;
}
tTriangulo * atualizaTriangulo(FILE *file, tTriangulo *triangulo) {

    fscanf(file," %f %f ", &triangulo->base,
            &triangulo->altura);
    return triangulo;
}

float areaTriangulo(tTriangulo* triangulo) {
    return ((triangulo->base * triangulo->altura) / 2);
}