//
// Created by mathe on 26/10/2019.
//

#include "Terreno.h"
#include <stdlib.h>
#include <string.h>

union formato {
    tTriangulo* Triangulo;
    tRetangulo* Retangulo;
    tTrapezio* Trapezio;
};
struct tipoterreno {
    char tipo_de_solo;
    unsigned int preco_m2_terreno;
    tFormato* formato;
    char* categoria;
    float area;
};

tTerreno * inicializaTipoTerreno() {
    tTerreno* aux;
    aux = (tTerreno*)malloc(sizeof(tTerreno));
    aux->formato = (tFormato*) malloc(sizeof(tFormato));
    return aux;
}

tTerreno* leTerreno(FILE* file, tTerreno* terreno, char* categoria) {
    terreno = inicializaTipoTerreno();
    terreno->categoria = (char*) malloc((strlen(categoria)+ 1)* sizeof (char));
    strcpy(terreno->categoria, categoria);
    fscanf(file," %c ", &terreno->tipo_de_solo);
    fscanf(file," %u ", &terreno->preco_m2_terreno);

    if(strcmp(terreno->categoria, "triang") == 0) {
        terreno->formato->Triangulo = leTriangulo(file, terreno->formato->Triangulo);
        terreno->area = areaTriangulo(terreno->formato->Triangulo);
        return terreno;
    }
    if(strcmp(terreno->categoria, "retang") == 0) {
        terreno->formato->Retangulo = leRetangulo(file, terreno->formato->Retangulo);
        terreno->area = areaRetangulo(terreno->formato->Retangulo);
        return terreno;
    }
    if(strcmp(terreno->categoria, "trapez") == 0) {
        terreno->formato->Trapezio = leTrapezio(file, terreno->formato->Trapezio);
        terreno->area = areaTrapezio(terreno->formato->Trapezio);
        return terreno;
    }

}

tTerreno* atualizaTerreno(FILE* file, tTerreno* terreno, char* categoria) {
    terreno->categoria = (char*)malloc(strlen((categoria)+1)*sizeof(char));
    terreno->formato= (tFormato*)malloc(sizeof(tFormato*));
    strcpy(terreno->categoria, categoria);

    fscanf(file," %c ", &terreno->tipo_de_solo);
    fscanf(file," %u ", &terreno->preco_m2_terreno);

    if(strcmp(terreno->categoria, "triang") == 0) {
        terreno->formato->Triangulo = atualizaTriangulo(file, terreno->formato->Triangulo);
        terreno->area = areaTriangulo(terreno->formato->Triangulo);
        return terreno;
    }
    if(strcmp(terreno->categoria, "retang") == 0) {
        terreno->formato->Retangulo = atualizaRetangulo(file, terreno->formato->Retangulo);
        terreno->area = areaRetangulo(terreno->formato->Retangulo);
        return terreno;
    }
    if(strcmp(terreno->categoria, "trapez") == 0) {
        terreno->formato->Trapezio = atualizaTrapezio(file, terreno->formato->Trapezio);
        terreno->area = areaTrapezio(terreno->formato->Trapezio);
        return terreno;
    }

}

float calculaPrecoTerreno(tTerreno *terreno) {
    float aux;
    switch(terreno->tipo_de_solo) {
        case 'A' :{
            aux = (float) terreno->preco_m2_terreno * terreno->area * 0.9;
            break;
        }
        case 'G' :{
            aux = terreno->preco_m2_terreno * terreno->area * 1.3;
            break;
        }
        case 'R' :{
            aux = terreno->preco_m2_terreno * terreno->area * 1.1;
            break;
        }
    }
    return aux;
}

int ehArgiloso(tTerreno *terreno) {
    if(terreno->tipo_de_solo == 'G') {
        return 1;
    }
    return 0;
}

int comparaAreaTerreno(tTerreno *terreno1, tTerreno *terreno2){
    if(terreno1->area > terreno2->area) {
        return 1;
    }
    if(terreno1->area < terreno2->area) {
        return -1;
    }
    // Se for igual
    return 0;
}

void liberaTerreno(tTerreno* terreno) {
    free(terreno->categoria);
    free(terreno->formato);
    free(terreno);
}