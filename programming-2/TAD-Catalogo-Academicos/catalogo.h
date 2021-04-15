//
// Created by 2019202297 on 31/10/19.
//

#ifndef TAD_CATALOGO_ACADEMICOS_CATALOGO_H
#define TAD_CATALOGO_ACADEMICOS_CATALOGO_H
#include "academico.h"

typedef struct catalogo tCatalogo;

tCatalogo* leCatalogo(FILE* file);

void apresentaCatalogo(tCatalogo* catalogo);

void ordenaPorNome(tCatalogo* catalogo, int cmp(tAcademico*,tAcademico*));

#endif //TAD_CATALOGO_ACADEMICOS_CATALOGO_H
