//
// Created by Matheus Lenke on 06/12/19.
//

#ifndef BANCO_BANCO_H
#define BANCO_BANCO_H

#include <stdlib.h>
#include <stdio.h>
#include "agencia.h"

typedef struct banco tBanco;

tBanco *leBanco(int codigoBanco);

tBanco *atualizaBanco(tBanco *banco);

int ehBanco(tBanco* banco, int codigobanco);

tCorrentista* retornaCorrentistaRicoBanco(tBanco* banco);

tAgencia* banco_retornaAgenciaMaisDebito(tBanco* banco);

tBanco* banco_atualizaSaldo(tBanco* banco);

tBanco* banco_retornaBancoMaisSaldo(tBanco* banco1, tBanco* banco2);

float banco_retornaSaldo(tBanco* banco);

void imprimeBanco(tBanco* banco);
#endif //BANCO_BANCO_H
