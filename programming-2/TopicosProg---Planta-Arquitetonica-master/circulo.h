#ifndef _CIRCULO
#define _CIRCULO
#include "ponto.h"

typedef struct {
    Tponto* origem;
    int raio;
} Tcirculo;

/*Le o circulo
* inputs: valores do circulo
* output: Um circulo criado
* pre-condicao: O circulo deve ter um centro e raio
* pos-condicao: O circulo será criado
*/
void lerCirculo(Tcirculo*);

void apresentarCirculo(Tcirculo*);

float areaCirculo (Tcirculo*);

float perimetroCirculo(Tcirculo*);

#endif
