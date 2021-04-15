#include "pais.h"
#include "paises.h"
#include <stdio.h>


void main (void) {

    FILE* file;
    file = fopen("entrada.txt", "r");

    leArquivo(file);
}