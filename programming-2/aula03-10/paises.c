#include <stdio.h>
#include <stdlib.h>
#include "paises.h"

int verificaExiste(int codigo, tPaises* paises) {

}

int leArquivo (FILE* file){

}

void inicializa(tPaises* paises){
    paises->qtd = 0;
    
}

void atualizaTorneio(tPaises* paises) {
    int medalha = 1;
    while(!feof(file)) {
        if (medalha == 3) {
            medalha = 1;
        }
        medalha++;
    }
}

void apresenta(tPais*){
    
}
