//
// Created by mathe on 27/10/2019.
//

#ifndef T1_TOPICOS_PROG_PRODUTO_H
#define T1_TOPICOS_PROG_PRODUTO_H

#include "Imovel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto tProduto;

tProduto * inicializaProduto();

tProduto* copiaProduto(tProduto* produto1, tProduto* produto2);

tProduto* leProduto(FILE* file, tProduto *produto);

void imprimeIdProduto(tProduto* produto);

tProduto* alteraProduto(FILE* file, tProduto *produto, char *categoria);

void trocaPosicaoProduto(tProduto *produto1, tProduto *produto2);

int comparaMaisCaro(tProduto *produto1, tProduto *produto2);

void removeChar(char *str, char garbage);

int ehProdutoEspec(tProduto *produto, float area_limite, float preco_limite);

int ehProdutoArgiloso(tProduto *produto);

int comparaAreaProduto(tProduto *produto1, tProduto *produto2);

int comparaQtdQuartosProduto(tProduto *produto1, tProduto *produto2, int ordem);

int retornaIdProduto(tProduto *produto);

void liberaProduto(tProduto* produto);

#endif //T1_TOPICOS_PROG_PRODUTO_H
