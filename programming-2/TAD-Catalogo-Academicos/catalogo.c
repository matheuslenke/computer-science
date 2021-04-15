//
// Created by 2019202297 on 31/10/19.
//

#include "catalogo.h"
#include "academico.h"

#define MAX_ACADEMICOS 30


struct catalogo {
    tAcademico* academicos[MAX_ACADEMICOS];
    int quantidade;
    int max;
};

tCatalogo* leCatalogo(FILE* file) {
    tCatalogo* catalogo;
    catalogo = (tCatalogo*)malloc(sizeof(tCatalogo));
    catalogo->quantidade = 0;

    do {
       catalogo->academicos[catalogo->quantidade] = leAcademico(file);
       catalogo->quantidade++;
    } while(feof(file) == 0);

    return catalogo;
}

void apresentaCatalogo(tCatalogo* catalogo) {

    for(int i = 0; i<catalogo->quantidade; i++) {
        apresentaAcademico(catalogo->academicos[i]);
    }
}

void ordenaPorNome(tCatalogo* catalogo, int cmp(tAcademico*,tAcademico*)) {
    tAcademico* aux;
    for(int i = 0; i<catalogo->quantidade - 1; i++) {
        for(int j = i +1; j<catalogo->quantidade -1; j++) {
            if(cmp(catalogo->academicos[i],catalogo->academicos[j])) {
                aux = catalogo->academicos[i];
                catalogo->academicos[i] = catalogo->academicos[j];
                catalogo->academicos[j] = aux;
            }
        }
    }
}
