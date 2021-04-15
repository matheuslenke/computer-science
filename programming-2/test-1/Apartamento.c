//
// Created by mathe on 26/10/2019.
//

#include "Apartamento.h"

struct tipoapartamento {
    unsigned int n_quartos;
    unsigned int n_vagas;
    unsigned int andar;
    float area_construida;
    unsigned int preco_m2_construido;
    char lazer;
    unsigned int total_andares;
};

tApartamento * inicializaApartamento() {
    tApartamento* apartamento = (tApartamento*)malloc(sizeof(tApartamento));
    return apartamento;
}

tApartamento* leApartamento(FILE* file, tApartamento *apartamento) {
    apartamento = inicializaApartamento();
    fscanf(file, " %u ", &apartamento->n_quartos);
    fscanf(file, " %u ", &apartamento->n_vagas);
    fscanf(file, " %u ", &apartamento->andar);
    fscanf(file, " %f ", &apartamento->area_construida);
    fscanf(file, " %u ", &apartamento->preco_m2_construido);
    fscanf(file, " %c ", &apartamento->lazer);
    fscanf(file, " %u ", &apartamento->total_andares);
    return apartamento;
}

tApartamento* atualizaApartamento(FILE* file, tApartamento *apartamento) {
    fscanf(file, " %u ", &apartamento->n_quartos);
    fscanf(file, " %u ", &apartamento->n_vagas);
    fscanf(file, " %u ", &apartamento->andar);
    fscanf(file, " %f ", &apartamento->area_construida);
    fscanf(file, " %u ", &apartamento->preco_m2_construido);
    fscanf(file, " %c ", &apartamento->lazer);
    fscanf(file, " %u ", &apartamento->total_andares);
}

//void imprimeApartamento(tApartamento apartamento) {
//    printf("Apartamento: \n qtos: %u vagas: %u andar: %u \n "
//           "area const: %lf preco m2: %u lazer: %c andares: %u", apartamento->n_quartos,
//           apartamento->n_vagas, apartamento->andar, apartamento->area_construida,
//           apartamento->preco_m2_construido, apartamento->lazer, apartamento->total_andares);
//}

float calculaPrecoApto(tApartamento* apto) {
    float aux;
    switch(apto->lazer) {
        case 'S': {
            aux = (float) ( apto->preco_m2_construido * apto->area_construida * (0.9 +
            (apto->andar / apto->total_andares)) * 1.15 );
        break;
        }
        case 'N': {
            aux = (float) ( (float) apto->preco_m2_construido * (float)apto->area_construida *
                    (float)
                    (0.9 +
            ((float)apto->andar / (float)apto->total_andares)) * (float)1.0 );
            break;
        }
    }
    return aux;
}

void liberaApartamento(tApartamento* apartamento) {
    free(apartamento);
}