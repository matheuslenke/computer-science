//
// Created by Matheus Lenke on 04/12/19.
//

#include "agencia.h"
#include <stdlib.h>
#include <string.h>

#define TAM_CORRENTISTAS 30

struct agencia {
    int codigobanco;
    int codigoAgencia;
    tCorrentista** correntistas;
    int quantidade_correntistas;
    float saldo;
    float debito;
};

tAgencia* inicializaAgencia() {
    tAgencia* agencia;
    agencia = (tAgencia*)malloc(sizeof(tAgencia));
    agencia->correntistas = (tCorrentista**)malloc(TAM_CORRENTISTAS * sizeof(tCorrentista*));
    agencia->quantidade_correntistas = 0;
    agencia->saldo = 0;
    return agencia;
}

tAgencia *leAgencia(int codigoAgencia, int codigobanco) {
    tAgencia* agencia;
    agencia = inicializaAgencia();
    float saldo;

    int numeroconta;
    agencia->codigobanco =  codigobanco;
    agencia->codigoAgencia = codigoAgencia;

    scanf(" %d ", &numeroconta);
    scanf(" %f ", &saldo);
    agencia->saldo += saldo;
    if(saldo < 0) {
        agencia->debito += (-saldo);
    }
    agencia->correntistas[agencia->quantidade_correntistas] = leCorrentista(numeroconta, codigobanco, codigoAgencia, saldo);
    agencia->quantidade_correntistas++;
    return agencia;
}

tAgencia *atualizaAgencia(tAgencia *agencia) {
    int numeroconta;
    int existe = 0;
    float saldo;
    scanf(" %d ", &numeroconta);
    scanf(" %f ", &saldo);
    agencia->saldo += saldo;
    if(saldo < 0) {
        agencia->debito += (-saldo);
    }
    for(int i = 0; i< agencia->quantidade_correntistas; i++) {
        if(ehCorrentista(agencia->correntistas[i], numeroconta) == 1) {
            existe = 1;
            agencia->correntistas[i] = atualizaCorrentista(agencia->correntistas[i], saldo);
        }
    }
    if(existe == 0) {
        agencia->correntistas[agencia->quantidade_correntistas] = leCorrentista(numeroconta, agencia->codigobanco,
                                                                                agencia->codigoAgencia, saldo);
        agencia->quantidade_correntistas++;
    }
    return agencia;
}
int ehAgencia(tAgencia* agencia, int codigoagencia) {
    if(agencia->codigoAgencia == codigoagencia) {
        return 1;
    }
    return 0;
}

tCorrentista* procuraCorrentistaRicoAgencia(tAgencia* agencia) {
    tCorrentista* aux;
    aux = agencia->correntistas[0];
    for(int i = 1; i< agencia->quantidade_correntistas; i++) {
        aux = comparaCorrentista(aux, agencia->correntistas[i]);
    }
    return aux;
}

tAgencia* agenciaMaisDebito(tAgencia* agencia1, tAgencia* agencia2) {
    if(agencia1->debito > agencia2->debito) {
        return agencia1;
    }
    else return agencia2;
}

float agencia_retornaDebito(tAgencia* agencia) {
    return agencia->debito;
}
float agencia_retornaSaldo(tAgencia* agencia) {
    return agencia->saldo;
}

void imprimeAgencia(tAgencia* agencia) {
    printf("Agencia: %d %d %.2f\n", agencia->codigobanco, agencia->codigoAgencia, agencia->saldo);
}