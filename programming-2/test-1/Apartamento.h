//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_APARTAMENTO_H
#define T1_TOPICOS_PROG_APARTAMENTO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct tipoapartamento tApartamento;

tApartamento * inicializaApartamento();

tApartamento* leApartamento(FILE* file, tApartamento *apartamento);

tApartamento* atualizaApartamento(FILE* file, tApartamento *apartamento);

float calculaPrecoApto(tApartamento *apto);

void liberaApartamento(tApartamento* apartamento);

#endif //T1_TOPICOS_PROG_APARTAMENTO_H
