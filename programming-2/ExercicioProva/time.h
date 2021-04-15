//
// Created by 2019202297 on 17/10/19.
//

#ifndef EXERCICIOPROVA_TIME_H
#define EXERCICIOPROVA_TIME_H

typedef struct {
    char* nome;
    int pontos, vitorias, pros, contras, saldo;
} tTime;

void inicializaTime(tTime*, char*, int, int);
void atualizarTime(tTime*, tTime*);
void apresentaTime(tTime*);
int comparaTimes(tTime*, tTime*);
int comparaPontos(tTime*, tTime*);
int comparaVitorias(tTime*, tTime*);
void apresentaNomeTime(tTime*);
int comparaNomeTimes(tTime*, tTime*);
#endif //EXERCICIOPROVA_TIME_H
