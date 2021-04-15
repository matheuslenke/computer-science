//
// Created by Matheus Lenke on 04/12/19.
//

#ifndef BANCO_CORRENTISTA_H
#define BANCO_CORRENTISTA_H

#include <stdio.h>
typedef struct tipocorrentista tCorrentista;

tCorrentista *leCorrentista(int numeroconta, int codigobanco, int codigoagencia, float saldo);

tCorrentista *atualizaCorrentista(tCorrentista *correntista, float saldo);

int ehCorrentista(tCorrentista* correntista, int numeroconta);

tCorrentista* comparaCorrentista(tCorrentista* correntista1, tCorrentista* correntista2);

void imprimeCorrentista(tCorrentista* correntista);

float retornaSaldoCorrentista(tCorrentista* correntista);
#endif //BANCO_CORRENTISTA_H
