//
// Created by Matheus Lenke on 06/12/19.
//

#include "banco.h"



#define MAX_TAM 50

struct banco {
    tAgencia** agencias;
    int quantidade;
    int codigoBanco;
    float saldo;
};

tBanco* inicializaBanco() {
    tBanco* banco = malloc(sizeof(tBanco));
    banco->agencias = malloc(MAX_TAM * sizeof(tAgencia*));
    banco->quantidade = 0;
    banco->saldo = 0;
    return banco;
}

tBanco *leBanco(int codigoBanco) {
    int codigoagencia;
    tBanco* banco = inicializaBanco();
    banco->codigoBanco = codigoBanco;
    scanf(" %d ", &codigoagencia);
    banco->agencias[banco->quantidade] = leAgencia(codigoagencia ,codigoBanco);
    banco->quantidade++;
    return banco;
}

tBanco *atualizaBanco(tBanco *banco) {
    int codigoagencia;
    int existe = 0;
    scanf(" %d ", &codigoagencia);
    for(int i = 0; i < banco->quantidade; i++) {
        if(ehAgencia(banco->agencias[i], codigoagencia) == 1) {
            existe= 1;
            banco->agencias[i] = atualizaAgencia(banco->agencias[i]);
        }
    }
    if(existe == 0) {
        banco->agencias[banco->quantidade] = leAgencia(codigoagencia, banco->codigoBanco);
        banco->quantidade++;
    }

    return banco;
}

int ehBanco(tBanco* banco, int codigobanco){
    if(banco->codigoBanco == codigobanco) {
        return 1;
    }
    return 0;

}

tCorrentista* retornaCorrentistaRicoBanco(tBanco* banco) {
    tCorrentista* aux;
    for(int i = 0; i<banco->quantidade; i++) {
        aux = procuraCorrentistaRicoAgencia(banco->agencias[i]);
    }
    return aux;
}

tAgencia* banco_retornaAgenciaMaisDebito(tBanco* banco) {
    tAgencia* aux;
    aux = banco->agencias[0];
    for(int i = 1; i<banco->quantidade; i++) {
       aux = agenciaMaisDebito(aux, banco->agencias[i]);
    }
    return aux;
}

tBanco* banco_atualizaSaldo(tBanco* banco) {
    for(int i = 0; i<banco->quantidade; i++) {
        banco->saldo += agencia_retornaSaldo(banco->agencias[i]);
    }
    return banco;
}

tBanco* banco_retornaBancoMaisSaldo(tBanco* banco1, tBanco* banco2) {
    if(banco1->saldo > banco2->saldo) {
        return banco1;
    }
    else {
        return banco2;
    }
}

float banco_retornaSaldo(tBanco* banco) {
    return banco->saldo;
}

void imprimeBanco(tBanco* banco) {
    printf("Banco: %d %.2f", banco->codigoBanco, banco->saldo);
}