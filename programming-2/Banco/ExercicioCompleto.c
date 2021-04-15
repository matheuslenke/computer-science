//
// Created by Matheus Lenke on 08/12/19.
//
#include <stdio.h>
#include <stdlib.h>

//main.c correntista.c correntista.h agencia.c agencia.h bancos.c bancos.h banco.c banco.h
typedef struct tipocorrentista tCorrentista;
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
    printf("Correntista: %.3d %d %d %.2f\n", correntista->codigobanco, correntista->codigoagencia, correntista->numeroConta,
           correntista->saldo);
}

float retornaSaldoCorrentista(tCorrentista* correntista) {
    return correntista->saldo;
}

#define TAM_CORRENTISTAS 30

typedef struct agencia tAgencia;

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
    printf("Agencia: %.3d %d %.2f\n", agencia->codigobanco, agencia->codigoAgencia, agencia->saldo);
}

#define MAX_TAM 50

typedef struct banco tBanco;

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
    printf("Banco: %.3d %.2f", banco->codigoBanco, banco->saldo);
}

// BANCOS

typedef struct bancocentral tBancoCentral;

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

int main() {
    tBancoCentral* bancocentral = inicializaBancoCentral();
    bancocentral = leBancoCentral();

    encontraCorrentistaRicoBancoCentral(bancocentral);
    encontraAgenciaMaisDebito(bancocentral);
    encontraBancoMaiorSaldo(bancocentral);
    return 0;
}