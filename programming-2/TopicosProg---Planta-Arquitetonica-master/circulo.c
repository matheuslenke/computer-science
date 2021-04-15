#include <stdio.h>
#include "circulo.h"
#include <math.h>

#define M_PI   3.14159265358979323846   /* pi */



void lerCirculo(Tcirculo* circulo) {
    lerPonto(circulo->origem);
    scanf("%d", &circulo->raio);
}

void apresentarCirculo(Tcirculo* circulo) {
    printf("Circulo: ");
    apresentarPonto( circulo->origem );
    printf(" raio: %d \n", circulo->raio);

}

float areaCirculo (Tcirculo* circulo){
    return pow((circulo->raio), 2) * M_PI;

}

float perimetroCirculo(Tcirculo* circulo){ 
    return 2*M_PI*(circulo->raio);

}
