#include <stdio.h>
#include <stdlib.h>
#include "planta.h"



int main(int argc, char const *argv[])
{

    printf("Ta funcionando a main");

    Tplanta* planta;

    lerPlanta(planta);
    
    exibePlanta(planta);
    return 0;

}
