//
// Created by mathe on 26/10/2019->
//

#include "Imovel.h"
#include <stdio.h>
#include <string.h>

union tipo_imovel {
tCasa* casa;
tApartamento* apartamento;
tTerreno* terreno;
};

struct tipoimovel{
    tipo_imovel* tipo;
    char* categoria;
    float preco;
};

tImovel * inicializaImovel() {
    tImovel* imovel = (tImovel*)malloc(sizeof(tImovel));
    imovel->tipo = (union tipo_imovel*)malloc(sizeof(union tipo_imovel));
    return imovel;
}

tImovel* leImovel(FILE* file, tImovel *imovel, char* categoria) {
    imovel = inicializaImovel();
    imovel->categoria = (char*) malloc((strlen(categoria)+1) * sizeof(char));
    strcpy(imovel->categoria, categoria);

    if (strcmp(categoria, "casa") == 0) {
        imovel->tipo->casa = leCasa(file, imovel->tipo->casa);
        imovel->preco = calculaPrecoImovel(imovel,categoria);
        return imovel;
    }
    if (strcmp(categoria, "apto") == 0) {
        imovel->tipo->apartamento = leApartamento(file, imovel->tipo->apartamento);
        imovel->preco = calculaPrecoImovel(imovel,categoria);
        return imovel;
    }
    if (strcmp(categoria, "triang") == 0 ||
        strcmp(categoria, "retang") == 0 ||
        strcmp(categoria, "trapez") == 0) {
        imovel->tipo->terreno = leTerreno(file, imovel->tipo->terreno, imovel->categoria);
        imovel->preco = calculaPrecoImovel(imovel,categoria);
        return imovel;
    }
}

tImovel* atualizaImovel(FILE* file, tImovel *imovel, char* categoria) {
    strcpy(imovel->categoria, categoria);

    if (strcmp(categoria, "casa") == 0) {
        imovel->tipo->casa =  atualizaCasa(file, imovel->tipo->casa);
        imovel->preco = calculaPrecoImovel(imovel,categoria);
        return imovel;
    }
    if (strcmp(categoria, "apto") == 0) {
        imovel->tipo->apartamento = atualizaApartamento(file, imovel->tipo->apartamento);
        imovel->preco = calculaPrecoImovel(imovel,categoria);
        return imovel;
    }
    if (strcmp(categoria, "triang") == 0 ||
    strcmp(categoria, "retang") == 0 ||
    strcmp(categoria, "trapez") == 0) {
        imovel->tipo->terreno = atualizaTerreno(file, imovel->tipo->terreno, imovel->categoria);
        imovel->preco = calculaPrecoImovel(imovel,categoria);
        return imovel;
    }
}

float calculaPrecoImovel(tImovel *imovel, char* categoria) {

    if (strcmp(categoria, "casa") == 0) {
       return calculaPrecoCasa(imovel->tipo->casa);
    }
    if (strcmp(categoria, "apto") == 0) {
         return calculaPrecoApto(imovel->tipo->apartamento);

    }
    if (strcmp(categoria, "triang") == 0 ||
        strcmp(categoria, "retang") == 0 ||
        strcmp(categoria, "trapez") == 0) {
        return calculaPrecoTerreno(imovel->tipo->terreno);
    }
}

int comparaPrecoImovel(tImovel *imovel1, tImovel *imovel2){
    if(imovel1->preco > imovel2->preco) {
        return 1;
    }
    if(imovel1->preco < imovel2->preco) {
        return -1;
    }
    if(imovel1->preco == imovel2->preco) {
        return 0;
    }
}

int comparaQtdQuartos(tImovel *imovel1, tImovel *imovel2){
    if(retornaQuartos(imovel1->tipo->casa) > retornaQuartos(imovel2->tipo->casa)) {
        return 1;
    }
    if(retornaQuartos(imovel1->tipo->casa) < retornaQuartos(imovel2->tipo->casa)) {
        return-1;
    }
    if(retornaQuartos(imovel1->tipo->casa) == retornaQuartos(imovel2->tipo->casa)) {
        return 0;
    }
}

int ehCasaEspecifica(tImovel* imovel, float area_limite, float preco_limite) {


    if(strcmp(imovel->categoria, "casa") == 0) {
        float area = retornaArea(imovel->tipo->casa);
        if (area > area_limite && imovel->preco < preco_limite) {
            return 1;
        }
        return 0;
    }
    else return 0;
}

int ehImovelArgiloso(tImovel *imovel) {
        return ehArgiloso(imovel->tipo->terreno);
}

int comparaAreaImovel(tImovel *imovel1, tImovel *imovel2) {
    return comparaAreaTerreno(imovel1->tipo->terreno, imovel2->tipo->terreno);
}

float retornaAreaImovel(tImovel* imovel) {

}

void liberaImovel(tImovel* imovel) {
    if(imovel != NULL) {
        if(strcmp(imovel->categoria, "casa") == 0) {
            liberaCasa(imovel->tipo->casa);
        }
        if(strcmp(imovel->categoria, "apto") == 0) {
            liberaApartamento(imovel->tipo->apartamento);
        }
        if(strcmp(imovel->categoria, "retang") == 0 || strcmp(imovel->categoria, "trapez") == 0 || strcmp(imovel->categoria, "triang") == 0) {
            liberaTerreno(imovel->tipo->terreno);
        }
        free(imovel->tipo);
        free(imovel->categoria);
        free(imovel);
    }

}


