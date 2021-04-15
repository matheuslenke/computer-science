#ifndef _PAISES
#define _PAISES
#include "pais.h"

#include <stdio.h>

typedef struct pais {
    tPais p[30];
    int qtd; 
} tPaises;

int leArquivo (FILE*);

void inicializa(tPaises*);

void atualizaTorneio(tPaises* paises);

void apresenta(tPaises*);

#endif