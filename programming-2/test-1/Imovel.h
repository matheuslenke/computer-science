//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_IMOVEL_H
#define T1_TOPICOS_PROG_IMOVEL_H

#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"

typedef union tipo_imovel tipo_imovel;

typedef struct tipoimovel tImovel;

tImovel * inicializaImovel();

tImovel* leImovel(FILE* file, tImovel *imovel, char* categoria);

tImovel* atualizaImovel(FILE* file, tImovel *imovel, char* categoria);

int comparaPrecoImovel(tImovel *imovel1, tImovel *imovel2);

float calculaPrecoImovel(tImovel *imovel, char* categoria);

int comparaQtdQuartos(tImovel *imovel1, tImovel *imovel2);

int ehImovelArgiloso(tImovel *imovel);

int comparaAreaImovel(tImovel *imovel1, tImovel *imovel2);

float retornaAreaImovel(tImovel* imovel);

int ehCasaEspecifica(tImovel *imovel, float area_limite, float preco_limite);

void liberaImovel(tImovel* imovel);

#endif //T1_TOPICOS_PROG_IMOVEL_H
