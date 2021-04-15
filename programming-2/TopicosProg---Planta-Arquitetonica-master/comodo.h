#ifndef _COMODO  
#define _COMODO  
#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"

typedef union forma
{
   Tretangulo* retangulo;
   Tcirculo* circulo;
   Ttriangulo* triangulo;
} Tforma;

typedef struct {
    Tforma* forma;
    char tag;
    float area, perimetro;
} Tcomodo;

void lerComodo(Tcomodo*);

float areaComodo (Tcomodo*);

float perimetroComodo(Tcomodo*);

#endif