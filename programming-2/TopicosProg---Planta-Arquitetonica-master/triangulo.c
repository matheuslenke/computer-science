#include <stdio.h>
#include "triangulo.h"
#include <math.h>

void lerTriangulo(Ttriangulo* triangulo){
    lerPonto(triangulo->v1);
    lerPonto(triangulo->v2);
    lerPonto(triangulo->v3);
    scanf("%f %f", &triangulo->base, &triangulo->altura);
}

void apresentarTriangulo(Ttriangulo* triangulo){
    printf("Triangulo: ");
    apresentarPonto( triangulo->v1);
    apresentarPonto( triangulo->v2);
    apresentarPonto( triangulo->v3);
    printf(" base: %f altura %f \n", triangulo->base, triangulo->altura);
}

float areaTriangulo (Ttriangulo* triangulo){
    return (triangulo->base * triangulo-> altura) / 2;
}

float perimetroTriangulo(Ttriangulo* triangulo){
    float per = distancia(triangulo->v1, triangulo->v2) + distancia(triangulo->v2, triangulo->v3) +
    distancia(triangulo->v1, triangulo->v3);
    return per;
}

