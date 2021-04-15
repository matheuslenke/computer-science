//
// Created by mathe on 26/10/2019.
//

#include "Casa.h"
struct tipocasa {
    unsigned int n_quartos;
    unsigned int n_vagas;
    unsigned int n_pavimentos;
    double area_construida;
    unsigned int preco_m2_construido;
    double area_livre;
    unsigned int preco_m2_livre;
};

tCasa * inicializaCasa() {
    tCasa* casa = (tCasa*) malloc(sizeof(tCasa));
    return casa;
}
tCasa* leCasa(FILE* file, tCasa* casa) {
    casa = inicializaCasa();
    fscanf(file," %u ", &casa->n_quartos);
    fscanf(file," %u ", &casa->n_vagas);
    fscanf(file," %u ", &casa->n_pavimentos);
    fscanf(file," %lf ", &casa->area_construida);
    fscanf(file," %u ", &casa->preco_m2_construido);
    fscanf(file," %lf ", &casa->area_livre);
    fscanf(file," %u ", &casa->preco_m2_livre);
    return casa;
}
tCasa* atualizaCasa (FILE* file, tCasa *casa) {
    fscanf(file," %u ", &casa->n_quartos);
    fscanf(file," %u ", &casa->n_vagas);
    fscanf(file," %u ", &casa->n_pavimentos);
    fscanf(file," %lf ", &casa->area_construida);
    fscanf(file," %u ", &casa->preco_m2_construido);
    fscanf(file," %lf ", &casa->area_livre);
    fscanf(file," %u ", &casa->preco_m2_livre);
    return casa;
}


int retornaQuartos(tCasa *casa) {
    return casa->n_quartos;
}
float calculaPrecoCasa(tCasa *casa) {
    return (float) (casa->preco_m2_construido * casa->area_construida * casa->n_pavimentos +
    casa->preco_m2_livre * casa->area_livre);
}

float retornaArea(tCasa *casa) {
    float area;
    area = casa->area_construida * casa->n_pavimentos;
    return area;
}

void liberaCasa(tCasa* casa) {
    free(casa);
}
