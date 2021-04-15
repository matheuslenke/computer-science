//
// Created by 2019202297 on 17/10/19.
//

#ifndef EXERCICIOPROVA_TORNEIO_H
#define EXERCICIOPROVA_TORNEIO_H

#define EXP_TORNEIO 10
#include "time.h"
#include "jogo.h"

typedef struct {
    tTime* time;
    int quantidade;
    int max;
} tTorneio;

void inicializarTorneio(tTorneio*);
void processarTorneio(tTorneio*);
tTime* procurarTimeTorneio(tTorneio*, tTime*);
void inserirTimeTorneio(tTorneio*, tTime*);
void atualizarTimeTorneio(tTorneio*, tTime*);
void apresentarTabelaTorneio(tTorneio*);
void apresentarNomesTimesTorneio(tTorneio*);
void ordena (tTorneio*, int (*cmp)(tTime, tTime));
void liberarTorneio(tTorneio*);
void liberarTorneioExpande(tTorneio*);


#endif //EXERCICIOPROVA_TORNEIO_H
