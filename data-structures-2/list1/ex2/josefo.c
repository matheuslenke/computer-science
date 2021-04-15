//
// Created by lenke on 21/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"
#include "lista.h"

TipoLista * criaCirculo(int N) {
    TipoLista* lista = InicializaLista();
    for(int i = N ; i>0; i--) {
        TipoItem * pessoa = InicializaTipoItem(i);
        Insere(pessoa, lista);
    }
    return lista;
}

void encontraLider(TipoLista* circulo, int M) {
    EncontraSobrevivente(circulo, M);
}

void liberaCirculo(TipoLista* circulo) {
    free(circulo);
}
