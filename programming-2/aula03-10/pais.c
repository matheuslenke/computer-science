#include <stdio.h>
#include <stdlib.h>
#include "pais.h"


tPais lePais (FILE* file, int qual_medalha) {
    int codigo;
    tPais pais;
    fscanf(file,"%d", &codigo );
    pais->codigo = codigo;
    if (qual_medalha == 1) {
        pais->bronze = 1;
        pais->prata = 0;
        pais->ouro = 0;
    }
    if (qual_medalha == 2) {
        pais->bronze = 0;
        pais->prata = 1;
        pais->ouro = 0;
    }
    if (qual_medalha == 3) {
        pais->bronze = 0;
        pais->prata = 0;
        pais->ouro = 1;
    }
    return pais;
}

void inicializaPais(int codigo) {
    tPais pais;
    pais.codigo = codigo;
    pais.ouro = 0;
    pais.prata = 0;
    pais.bronze = 0;
}

void incrementa(tPais* pais, int b, int p, int o) {
    pais->bronze ++;
    pais->prata ++;
    pais->ouro ++;
}

void apresenta(tPais* pais) {

    printf("Codigo do pais: %d Bronze: %d Prata: %d Ouro: %d",
    pais->codigo, pais->bronze, pais->prata, pais->ouro);

}