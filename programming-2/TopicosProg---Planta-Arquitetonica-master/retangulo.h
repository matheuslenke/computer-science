#ifndef _RETANGULO  
#define _RETANGULO  
#include "ponto.h"

typedef struct {
    Tponto* supEsq, *infDir;
    float base, altura;
} Tretangulo;


void lerRetangulo(Tretangulo*);

float calcularBase(Tretangulo*);

float calcularAltura(Tretangulo*);

void apresentarRetangulo(Tretangulo*);

float areaRetangulo (Tretangulo*);

float perimetroRetangulo(Tretangulo*);

#endif