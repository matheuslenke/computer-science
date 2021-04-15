//
// Created by Matheus Lenke on 04/12/19.
//

#ifndef BANCO_BANCOS_H
#define BANCO_BANCOS_H

#include "agencia.h"
#include "banco.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct bancocentral tBancoCentral;

tBancoCentral* inicializaBancoCentral();

tBancoCentral* leBancoCentral();

tCorrentista* encontraCorrentistaRicoBancoCentral(tBancoCentral* bancocentral);

void encontraAgenciaMaisDebito(tBancoCentral* bancocentral);

void encontraBancoMaiorSaldo(tBancoCentral* bancocentral);
#endif //BANCO_BANCOS_H
