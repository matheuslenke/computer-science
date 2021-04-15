//
// Created by Matheus Lenke on 05/12/19.
//

#include "produto.h"

struct produto {
    int codigoProduto;
    float valor;
    float valorTotal;
    int quantidade;
};

tProduto *leProduto(int codigo) {
    tProduto* produto;
    produto = (tProduto*)malloc(sizeof(tProduto));
    produto->codigoProduto = codigo;
    scanf(" %f ", &produto->valor);
    scanf(" %d ", &produto->quantidade);
    produto->valorTotal = produto->valor * (float)produto->quantidade;
    return produto;
}

tProduto *atualizaProduto(tProduto *produto) {
    int quantidade;
    scanf(" %f ", &produto->valor);
    scanf(" %d ", &quantidade);
    produto->quantidade += quantidade;
    produto->valorTotal += produto->valor * (float)quantidade;
    return produto;
}

int ehProduto(tProduto* produto, int codigo) {
    if(produto->codigoProduto == codigo) {
        return 1;
    }
    return 0;
}

void imprimeProduto(tProduto* produto) {
    printf("%d Unidades: %d Valor total: R$%.2f\n", produto->codigoProduto, produto->quantidade, produto->valorTotal);
}
int comparaProdutoQuantidade(tProduto* produto1, tProduto* produto2){
    if(produto1->quantidade < produto2->quantidade) {
        return 1;
    }
    else if(produto1->quantidade > produto2->quantidade) {
        return -1;
    }
    return 0;
}
int comparaProdutoValor(tProduto* produto1, tProduto* produto2){
    if(produto1->valorTotal < produto2->valorTotal) {
        return 1;
    }
    else if(produto1->valorTotal > produto2->valorTotal) {
        return -1;
    }
    return 0;
}