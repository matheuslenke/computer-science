//
// Created by Matheus Lenke on 04/12/19.
//

#ifndef BANCO_AGENCIA_H
#define BANCO_AGENCIA_H

#include "correntista.h"

typedef struct agencia tAgencia;

tAgencia *leAgencia(int codigoAgencia, int codigobanco);

tAgencia *atualizaAgencia(tAgencia *agencia);

int ehAgencia(tAgencia* agencia, int codigoagencia);

tCorrentista* procuraCorrentistaRicoAgencia(tAgencia* agencia);

tAgencia* agenciaMaisDebito(tAgencia* agencia1, tAgencia* agencia2);

float agencia_retornaDebito(tAgencia* agencia);

void imprimeAgencia(tAgencia* agencia);

float agencia_retornaSaldo(tAgencia* agencia);

#endif //BANCO_AGENCIA_H
