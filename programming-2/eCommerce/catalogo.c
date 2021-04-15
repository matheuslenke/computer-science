//
// Created by Matheus Lenke on 05/12/19.
//

#include "catalogo.h"
#define MAX_TAM 50


struct catalogo {
    tProduto** produtos;
    int quantidade;
    int maxTam;
};
tCatalogo* inicializaCatalogo() {
    tCatalogo* catalogo;
    catalogo = (tCatalogo*)malloc(sizeof(tCatalogo));
    catalogo->produtos = (tProduto**)malloc(MAX_TAM * sizeof(tProduto*));
    catalogo->quantidade = 0;
    catalogo->maxTam = MAX_TAM;
    return catalogo;
}
tCatalogo *leCatalogo(tCatalogo *catalogo) {
    int codigoproduto;
    int produtoexiste = 0;
    while (scanf("%d ", &codigoproduto) == 1) {
        for(int i = 0; i < catalogo->quantidade; i++) {
            if(ehProduto(catalogo->produtos[i], codigoproduto) == 1) {
                atualizaProduto(catalogo->produtos[i]);
                produtoexiste = 1;
            }
        }
        if(produtoexiste == 0) {
            catalogo->produtos[catalogo->quantidade] = leProduto(codigoproduto);
            catalogo->quantidade++;
        }
        produtoexiste = 0;
    }
    return catalogo;
}

void imprimeCatalogo(tCatalogo* catalogo) {
    for(int i = 0; i<catalogo->quantidade; i++) {
        imprimeProduto(catalogo->produtos[i]);
    }
}
void imprimeMaisVendidos(tCatalogo* catalogo) {
    for(int i = 0; i<2; i++) {
        imprimeProduto(catalogo->produtos[i]);
    }
}
void imprimeMenosValioso(tCatalogo* catalogo) {
    imprimeProduto(catalogo->produtos[0]);
}


tCatalogo *ordenaCatalogo(tCatalogo *catalogo, int (*cmp)(tProduto *, tProduto *), int ordem) {
    tProduto* aux;

    //Crescente
    if(ordem == 0) {
        for(int i = 0; i< catalogo->quantidade; i++) {
            for(int j = i+1; j<catalogo->quantidade; j++) {
                if(cmp(catalogo->produtos[i], catalogo->produtos[j]) == 1) {
                    aux = catalogo->produtos[i];
                    catalogo->produtos[i] = catalogo->produtos[j];
                    catalogo->produtos[j] = aux;
                }
            }
        }
    }
    // Descrescente
    if(ordem == 1) {
        for(int i = 0; i< catalogo->quantidade; i++) {
            for(int j = i+1; j<catalogo->quantidade; j++) {
                if(cmp(catalogo->produtos[i], catalogo->produtos[j]) == -1) {
                    aux = catalogo->produtos[i];
                    catalogo->produtos[i] = catalogo->produtos[j];
                    catalogo->produtos[j] = aux;
                }
            }
        }
    }
    return catalogo;
}

void liberaCatalogoTodo(tCatalogo* catalogo) {
    for(int i = 0; i< catalogo->quantidade; i++) {
        free(catalogo->produtos[i]);
    }
    free(catalogo->produtos);
    free(catalogo);
}

