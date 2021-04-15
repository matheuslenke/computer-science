//
// Created by Matheus Lenke on 04/12/19.
//

#include "bancos.h"
#define MAX_BANCOS 50

struct bancocentral {
    tBanco ** bancos;
    int quantidade;
};

tBancoCentral* inicializaBancoCentral() {
    tBancoCentral* bancos;
    bancos = (tBancoCentral*) malloc(sizeof(tBancoCentral));
    bancos->bancos = (tBanco**) malloc(MAX_BANCOS * sizeof(tBanco*));
    bancos->quantidade = 0;
    return bancos;

}
tBancoCentral *leBancoCentral() {
    tBancoCentral* bancocentral = inicializaBancoCentral();
    int codigobanco, existe;

    while(scanf(" %d ", &codigobanco) == 1) {
        existe = 0;
        for(int i = 0; i < bancocentral->quantidade; i++) {
            if(ehBanco(bancocentral->bancos[i], codigobanco) == 1) {
                bancocentral->bancos[i] = atualizaBanco(bancocentral->bancos[i]);
                existe = 1;
            }
        }
        if (existe == 0) {
            bancocentral->bancos[bancocentral->quantidade] = leBanco(codigobanco);
            bancocentral->quantidade++;
        }

    }
    return bancocentral;
}

tCorrentista* encontraCorrentistaRicoBancoCentral(tBancoCentral* bancocentral) {
    tCorrentista* aux, *maisrico;
    for(int i = 0; i<bancocentral->quantidade; i++) {
        aux = retornaCorrentistaRicoBanco(bancocentral->bancos[i]);
        if(i == 0) {
            maisrico = aux;
        }
        else {
            if(retornaSaldoCorrentista(aux) > retornaSaldoCorrentista(maisrico)) {
                maisrico = aux;
            }
        }
    }
    // Achou o mais rico:
    imprimeCorrentista(maisrico);
}

void encontraAgenciaMaisDebito(tBancoCentral* bancocentral) {
    tAgencia* aux, *maisdebito;
    for(int i = 0; i<bancocentral->quantidade; i++) {
        aux = banco_retornaAgenciaMaisDebito(bancocentral->bancos[i]);
        if(i == 0) {
            maisdebito = aux;
        }
        else {
            if(agencia_retornaDebito(aux) > agencia_retornaDebito(maisdebito)) {
                maisdebito = aux;
            }
        }
    }

    // Achou a com mais debito

    imprimeAgencia(maisdebito);
}
void encontraBancoMaiorSaldo(tBancoCentral* bancocentral) {
    tBanco* aux, *maisSaldo;

    for(int i = 0; i<bancocentral->quantidade; i++) {
        bancocentral->bancos[i] = banco_atualizaSaldo(bancocentral->bancos[i]);
        aux = bancocentral->bancos[i];

        if(i == 0) {
            maisSaldo = aux;
        }
        else {
            maisSaldo = banco_retornaBancoMaisSaldo(aux, maisSaldo);
        }
    }

    // Achou a com mais debito

    imprimeBanco(maisSaldo);
}