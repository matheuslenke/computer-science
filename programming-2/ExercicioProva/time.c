//
// Created by 2019202297 on 17/10/19.
//

#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializaTime(tTime* t, char* nome, int golpro, int golcontra) {
    t->nome = (char*)malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(t->nome, nome);
    if(golpro > golcontra) {
        t->pontos = 3;
        t->vitorias = 1;
    }
    else if(golpro < golcontra) {
        t->pontos = 0;
        t->vitorias = 0;
    }
    else {
        t->pontos = 1;
        t->vitorias = 0;
    }
    t->pros = golpro;
    t->contras = golcontra;
    t->saldo = golpro - golcontra;

}

void apresentaTime(tTime* t) {
    printf("Nome %s, Vitorias:: %d, Marcados: %d, sofridos: %d, Saldo: %d\n",
            t->nome,
            t->vitorias,
            t->pros,
            t->contras,
            t->saldo);

}

void apresentaNomeTime(tTime* t) {
    printf("Nome: %s", t->nome);
}

void atualizarTime(tTime* time1, tTime* time2) {
    time1->vitorias += time2->vitorias;
    time1->pontos += time2->pontos;
    time1->pros += time2->pros;
    time1->contras += time2->contras;
    time1->saldo += time2->saldo;
}

int comparaNomeTimes(tTime* time1, tTime* time2) {
    return strcmp(time1->nome, time2->nome);
}

int comparaTimes(tTime* time1, tTime* time2) {
    if(time2->pontos > time1->pontos) {
        return 1;
    }
    if (time2->pontos == time1->pontos && time2->vitorias > time1->vitorias) {
        return 1;
    }
    if(time2->pontos == time1->pontos && time2->vitorias == time1->vitorias && time2->saldo > time1->saldo) {
        return 1;
    }
    if(time2->pontos == time1->pontos && time2->vitorias == time1->vitorias && time2->saldo == time1->saldo &&
    time2->pros > time1->pros) {
        return 1;
    }
    if (time2->pontos == time1->pontos && time2->vitorias == time1->vitorias && time1->saldo == time2->saldo &&
    time2->pros == time1 -> pros) {
        return (comparaNomeTimes(time1, time2) < 0);
    }
    return 0;
}

int comparaPontos(tTime* time1, tTime* time2) {
    if(time1->pros > time2 -> pros) {
        return 0;
    }
    if(time1->pros < time2->pros) {
        return 1;
    }
    return(comparaNomeTimes(time1,time2) < 0);
}

int comparaVitorias(tTime* time1, tTime* time2) {
    if (time1->vitorias > time2->vitorias) {
        return 1;
    }
    if ( time1->vitorias < time2->vitorias) {
        return 0;
    }
    return (comparaNomeTimes(time1,time2) < 0);

}

void liberaNomeTime(tTime* t) {
    free(t->nome);
}

