#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"
#include "comodo.h"
#include <stdio.h>
#include <stdlib.h>

void lerComodo(Tcomodo* comodo) {
    char tipo;

    scanf("%c", &tipo);
    switch (tipo)
    {
    case 'C':
        lerCirculo(comodo->forma->circulo);
        comodo->tag = 'C';
        break;
    case 'R':
        lerRetangulo(comodo->forma->retangulo);
        comodo->tag = 'R';
        break;
    case 'T':
        lerTriangulo(comodo->forma->triangulo);
        comodo->tag = 'T';
        break;
    }
}

float areaComodo (Tcomodo* comodo) {
    switch (comodo->tag)
    {
    case 'C':
        comodo->area = areaCirculo(comodo->forma->circulo);
        break;
    
    case 'R':
        comodo->area = areaRetangulo(comodo->forma->retangulo);
        break;
    
    case 'T':
        comodo->area = areaTriangulo(comodo->forma->triangulo);
        break;
    }
    return comodo->area;
}

float perimetroComodo(Tcomodo* comodo) {
    switch (comodo->tag)
    {
    case 'C':
        comodo->perimetro = perimetroCirculo(comodo->forma->circulo);
        break;
    
    case 'R':
        comodo->perimetro = perimetroRetangulo(comodo->forma->retangulo);
        break;
    
    case 'T':
        comodo->perimetro = perimetroTriangulo(comodo->forma->triangulo);
        break;
    }
    return comodo->perimetro;
}
