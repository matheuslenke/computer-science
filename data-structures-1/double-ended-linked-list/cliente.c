#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"


void main(void) {

    TipoListaDpl* lista;
    TipoItem* matheus;
    lista = NULL;
    matheus = InicializaTipoItem("Matheus", 2019202297, "Rua Carijos");
    TipoItem* maria = InicializaTipoItem("maria", 123, "rua da maria");
    TipoItem* sofia = InicializaTipoItem("sofia", 2345, "rua da sofia");
    TipoItem* jose = InicializaTipoItem("jose", 4523, "rua do jose");
    TipoItem* joao = InicializaTipoItem("joao", 34, "rua do joao");
    TipoItem* catarina = InicializaTipoItem("catarina", 987, "rua da catarina");

    lista = Insere(matheus, lista);
    lista = Insere(maria, lista);
    lista = Insere(sofia, lista);
    lista = Insere(jose, lista);
    lista = Insere(joao, lista);
    lista = Insere(catarina, lista);
    Imprime(lista);

    printf("Após retirada \n");

    Retira(lista, "Matheus");

    Imprime(lista);

    libera(lista);
    
}
