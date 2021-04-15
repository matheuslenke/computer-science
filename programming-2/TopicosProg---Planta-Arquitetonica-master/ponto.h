#ifndef _PONTO
#define _PONTO
#include <stdio.h>
#include <math.h>

typedef struct ponto{
int x, y;
} Tponto;

/*Lê o ponto
* inputs: Ponto
* output: 
* pre-condicao: O ponto existe
* pos-condicao: Não altera nada
*/
void lerPonto(Tponto*);


void apresentarPonto(Tponto*);


float distancia (Tponto*, Tponto*);


#endif
