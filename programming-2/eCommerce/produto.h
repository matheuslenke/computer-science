//
// Created by Matheus Lenke on 05/12/19.
//

#ifndef ECOMMERCE_PRODUTO_H
#define ECOMMERCE_PRODUTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct produto tProduto;

tProduto *leProduto(int codigo);

tProduto *atualizaProduto(tProduto *produto);

int ehProduto(tProduto* produto, int codigo);

void imprimeProduto(tProduto* produto);

int comparaProdutoQuantidade(tProduto* produto1, tProduto* produto2);

int comparaProdutoValor(tProduto* produto1, tProduto* produto2);
#endif //ECOMMERCE_PRODUTO_H
