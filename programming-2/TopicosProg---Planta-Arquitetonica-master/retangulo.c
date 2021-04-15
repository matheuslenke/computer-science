#include <stdio.h>
#include "retangulo.h"
#include <math.h>

void lerRetangulo(Tretangulo* retangulo) {
    lerPonto(retangulo->supEsq);
    lerPonto(retangulo->infDir);
    calcularBase(retangulo);
    calcularAltura(retangulo);
}
float calcularBase(Tretangulo* retangulo){
    float base = retangulo->supEsq->x - retangulo->infDir->x;
    return base;
}

float calcularAltura(Tretangulo* retangulo){
  float altura = retangulo->supEsq->y -     retangulo->infDir->y;
  return altura;
}

void apresentarRetangulo(Tretangulo* retangulo){
    printf("Retangulo: ");
    apresentarPonto( retangulo->supEsq);
    apresentarPonto( retangulo->infDir);
}

float areaRetangulo (Tretangulo* retangulo){
    retangulo->base = calcularBase(retangulo);
    retangulo->altura = calcularAltura(retangulo);
    return ((retangulo->base * retangulo-> altura) / 2);
}

float perimetroRetangulo(Tretangulo* retangulo){
    float per = (retangulo->supEsq->x - retangulo->infDir->x) * 2 + retangulo->supEsq->y - retangulo->infDir->y;
    return per;
}

