#ifndef _PLANTA  
#define _PLANTA  
#include "comodo.h"

#define MAX_COMODOS 50

typedef struct {
    Tcomodo comodos[MAX_COMODOS];
    float areaPlanta, perimetroPlanta;
} Tplanta;

void lerPlanta(Tplanta*);

float areaPlanta (Tplanta*);

float perimetroPlanta(Tplanta*);

void exibePlanta(Tplanta*);

#endif