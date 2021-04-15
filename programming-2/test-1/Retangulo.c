//
// Created by mathe on 26/10/2019.
//

#include "Retangulo.h"
#include <stdio.h>

struct retangulo {
    float lado1, lado2;
};

tRetangulo* inicializaRetangulo() {
    tRetangulo* retangulo = (tRetangulo*)malloc(sizeof(tRetangulo));
    return retangulo;
}
tRetangulo* leRetangulo(FILE *file, tRetangulo* retangulo) {
    retangulo = inicializaRetangulo();
    fscanf(file," %f %f ", &retangulo->lado1,
           &retangulo->lado2);
    return retangulo;
}
tRetangulo* atualizaRetangulo(FILE *file, tRetangulo* retangulo) {
    fscanf(file," %f %f ", &retangulo->lado1,
           &retangulo->lado2);
    return retangulo;
}

float areaRetangulo(tRetangulo *retangulo) {
    return (retangulo->lado1 * retangulo->lado2);
}