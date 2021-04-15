#ifndef _PAIS
#define _PAIS
#include <stdio.h>

typedef struct pais {
    int codigo;
    int ouro;
    int prata;
    int bronze;
}tPais;

tPais lePais (FILE*, int);

void inicializaPais(int codigo);

void incrementa(tPais*, int medalha);

int maisMedalhas(tPais*, tPais*);

void apresenta(tPais*);

#endif