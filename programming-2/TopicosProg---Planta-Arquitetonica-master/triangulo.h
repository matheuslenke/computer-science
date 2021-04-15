#ifndef _TRIANGULO  
#define _TRIANGULO  
#include "ponto.h"

typedef struct {
    Tponto* v1, *v2, *v3;
    float base, altura;
} Ttriangulo;

/*Le o triangulo
* inputs: valores do triangulo
* output: Um triangulo criado
* pre-condicao: O triangulo deve ter um centro e raio
* pos-condicao: O triangulo será criado
*/
void lerTriangulo(Ttriangulo*);

void apresentarTriangulo(Ttriangulo*);

float areaTriangulo (Ttriangulo*);

float perimetroTriangulo(Ttriangulo*);

#endif
