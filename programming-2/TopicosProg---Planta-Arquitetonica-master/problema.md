• Calcular o perímetro e área de uma edificação planar em uma planta arquitetônica compostas por cômodos compostos por circulos, triângulos e retângulos não superpostos.
Considere que os dados da planta estão em um arquivo "planta.txt".
• Considere que um círculo contém um ponto de origem e seu raio, que um triângulo contém 3 pontos representando seus vértices, sua base e altura, e um retângulo contém 2 pontos representando seus vértices superior esquerdo e inferior direito.
Considere que o arquivo tem informação de cada cômodo em uma linha.
•  Apresentar os dados dos cômodos da planta em ordem de área e dos ordenados por perímetro
Exemplo:
C 1 3 2
T 1 8 3 5 7 9 3 2
R 3 5 15 2

Ponto
Círculo
Triângulo
Retângulo
Comodo
Planta


Ponto: 
Int x,y
• Ler
• apresentar
• distância

Círculo:
• Ponto
• Raio
• area
• perímetro
• apresentar
• ler

Triângulo:
• Ponto v1, v2, v3
• float base, altura
• area
• perímetro
• ler
• apresentar

Retângulo:
• Ponto supesq, infdir
• calcular base
• calcular altura
• area
• perímetro
• ler
• apresentar

Circulos: 
vetor de circulos
Int ncirculos
• inserir círculo
• área
• perímetro

Triângulos:
Vetor de triângulos
Int ntriangulos
• Inserir
• área
• perímetro

Retângulos:
Vetor de retângulos
Int nretangulos
• Inserir
• área
• perímetro

Cômodo:
Union
Tipo
Área perímetro

Typedef union {
Circulo c;
Triangulo t;
Retangulo r;
} Tforma;

Typedef struct {
Tforma t;
Char tag;
Float area;
Float perimetro;
} Tcomodo;

Typedef struct {
 Tcomodo t[ ];
 } Tplanta;

Union: superposição de struct

Typedef union {
Int x;
Float y;
} Xpto;

Só vai existir ou o x ou o y em uma union


Ponto.h

#ifndef _PONTO
#define _PONTO
typedef struct {
Int x, y;
} Tponto;

Void lerponto(tponto*);
Void apresentarponto(tponto*);
Float distancia (tponto*, tponto*);
#endif

Ponto.c
#include <stdio.h>
#include <math.h>
#include "ponto.h"

Void lerponto(tponto *p) {
Scanf("%d%d", &p->x , &p->y);
}

Void apresentar ponto (tponto *p) {
Printf("(%d,%d)", p->x, p->y);
}

Float distancia (tponto *p1, tponto *p2) {
Return sqrr( sqr(p1->x - p2->x) + sqr(p1->y - p2-> y);
}


Circulo.h

#ifndef _CIRCULO
  #define _CIRCULO
typedef struct {
Tponto org;
Int raio;
} Tcirculo;

Void lercirculo(tcirculo*);
Void apresentarcirculo(tcirculo*);
Float areaCirculo (Tcirculo*);
Float perimetroCirculo(tCirculo*);
#endif


Circulo.c
#include <stdio.h>
#include <math.h>
#include "circulo.h"

Void lercirculo(tcirculo *c){
  Lerponto(&c->org)
Scanf("%d", c->raio);
}

Void apresentarcirculo (tcirculo *c) {
Printf("Origem: ");
Apresentarpinto(&c->org);
printf( "raio : %d", c->raio);
}

Float areacirculo (tcirculo *c) {
Return   (pow(c->raio,2) * M_PI ) / 4
}



