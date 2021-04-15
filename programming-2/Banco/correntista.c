//
// Created by Matheus Lenke on 04/12/19.
//

#include "correntista.h"
#include <stdlib.h>
#include <string.h>

struct tipocorrentista{
    int codigobanco;
    int codigoagencia;
    int numeroConta;
    float saldo;
};

tCorrentista *leCorrentista(int numeroconta, int codigobanco, int codigoagencia, float saldo) {
    tCorrentista* correntista;
    correntista = (tCorrentista*)malloc(sizeof(tCorrentista));
    correntista->numeroConta = numeroconta;
    correntista->codigobanco = codigobanco;
    correntista->codigoagencia = codigoagencia;
    correntista->saldo = saldo;

    return correntista;
}
tCorrentista *atualizaCorrentista(tCorrentista *correntista, float saldo) {
    correntista->saldo += saldo;
    return correntista;
}

int ehCorrentista(tCorrentista* correntista, int numeroconta) {
    if(correntista->numeroConta == numeroconta) {
        return 1;
    }
    return 0;
}
tCorrentista* comparaCorrentista(tCorrentista* correntista1, tCorrentista* correntista2) {
    if(correntista1->saldo < correntista2->saldo) {
        return correntista2;
    }
    else {
        return correntista1;
    }
}

void imprimeCorrentista(tCorrentista* correntista) {
    printf("Correntista: %d %d %d %.2f\n", correntista->codigobanco, correntista->codigoagencia, correntista->numeroConta,
            correntista->saldo);
}

float retornaSaldoCorrentista(tCorrentista* correntista) {
    return correntista->saldo;
}