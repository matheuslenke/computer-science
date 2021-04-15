//
// Created by mathe on 26/10/2019.
//

#ifndef T1_TOPICOS_PROG_CATALOGO_H
#define T1_TOPICOS_PROG_CATALOGO_H

#include "Produto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * @param oie
 */
typedef struct catalogo tCatalogo;

tCatalogo* leCatalogo(FILE* file, tCatalogo *catalogo);

tCatalogo* atualizaCatalogo(FILE* file, tCatalogo *catalogo);

tCatalogo* copiaCatalogo(tCatalogo* catalogo1, tCatalogo* catalogo2);

tProduto * buscaProduto(tCatalogo *catalogo, int id, int qtd);

void imprimeCatalogo(tCatalogo* catalogo);

void modificaProduto(tCatalogo* catalogo, tProduto* produto);

tCatalogo * incrementaCatalogo(tCatalogo *catalogo);

        int buscaIndexProduto(tCatalogo *catalogo, int id, int qtd);

void OrdenaCatalogoSpec(FILE* arq_spec, tCatalogo *catalogo);

void ordenaImoveis(tCatalogo *catalogo, int cmp(tProduto*, tProduto*), int ordem);

int calculaArgilosos(tCatalogo *catalogo);

tCatalogo * retornaArgilosos(tCatalogo *catalogo);

void ordenaArgilosos(tCatalogo *catalogo, int cmp(tProduto *, tProduto *), int ordem);

tCatalogo * casasRefatoradas(tCatalogo *catalogo, float area_limite, float preco_limite);

void ordenaQuartos(tCatalogo *catalogo, int cmp(tProduto*, tProduto*, int), int ordem);

void gravarArquivoSaida (tCatalogo *catalogo1, tCatalogo *catalogo2, tCatalogo *catalogo3, int i,
                         int j, int k);

tCatalogo * inicializaTipoCatalogo();


void liberaCatalogoTodo(tCatalogo *catalogo);

void liberaCatalogo (tCatalogo* catalogo);

#endif //T1_TOPICOS_PROG_CATALOGO_H
