//
// Created by Matheus Lenke on 05/12/19.
//

#ifndef ECOMMERCE_CATALOGO_H
#define ECOMMERCE_CATALOGO_H

#include "produto.h"

typedef struct catalogo tCatalogo;

tCatalogo* inicializaCatalogo();

tCatalogo *leCatalogo(tCatalogo *catalogo);

tCatalogo *ordenaCatalogo(tCatalogo *catalogo, int (*cmp)(tProduto *, tProduto *), int ordem);

void imprimeCatalogo(tCatalogo* catalogo);

void imprimeMaisVendidos(tCatalogo* catalogo);

void imprimeMenosValioso(tCatalogo* catalogo);

void liberaCatalogoTodo(tCatalogo* catalogo);


#endif //ECOMMERCE_CATALOGO_H
