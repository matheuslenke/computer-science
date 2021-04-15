#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"
#include "comodo.h"
#include "planta.h"
#include <stdio.h>
#include <stdlib.h>


void lerPlanta(Tplanta* planta) {
    for (int i = 0; i < MAX_COMODOS; i++) {
        lerComodo(&(planta->comodos[i]));
    }
}

float areaPlanta (Tplanta* planta){
    for (int i = 0; i< MAX_COMODOS; i++){
        planta->areaPlanta += areaComodo(&planta->comodos[i]); 
    }
}

float perimetroPlanta(Tplanta* planta){
    for (int i = 0; i< MAX_COMODOS; i++){
        planta->perimetroPlanta += perimetroComodo(&planta->comodos[i]); 
    }
}

void exibePlanta(Tplanta* planta){
    for (int i = 0; i< MAX_COMODOS; i++){
        printf("A area total da planta é: %f \n O Perimetro total da planta é: %f", planta->areaPlanta, planta->perimetroPlanta);
    }
}