//
// Created by 2019202297 on 17/10/19.
//

#include "torneio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializarTorneio(tTorneio* torneio) {
    torneio->quantidade = 0;
    torneio->time = (tTime*)malloc(sizeof(tTime) * EXP_TORNEIO);
    if ( torneio->time == NULL) {
        exit(1);
    }
}
void processarTorneio(tTorneio* torneio) {

}
tTime* procurarTimeTorneio(tTorneio* torneio, tTime* time) {

}
void inserirTimeTorneio(tTorneio* torneio, tTime* time) {

}
void atualizarTimeTorneio(tTorneio* torneio, tTime* time) {

}
void apresentarTabelaTorneio(tTorneio* torneio) {

}
void apresentarNomesTimesTorneio(tTorneio* torneio) {

}
void ordena (tTorneio* torneio, int (*cmp)(tTime, tTime)) {

}
void liberarTorneio(tTorneio* torneio) {

}
void liberarTorneioExpande(tTorneio* torneio) {

}
