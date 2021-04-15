#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

struct matriz {
   int nlinhas;
   int ncolunas;
   int** malocada;
};

Matriz* inicializaMatriz (int nlinhas,int ncolunas) {

    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    mat->nlinhas = nlinhas;
    mat->ncolunas = ncolunas;
    mat->malocada = (int**)malloc(nlinhas*sizeof(int*));

    for (int i = 0; i < nlinhas; i++) {
        mat ->malocada[i] = (int*)malloc(ncolunas*sizeof(int));
    }
return mat;
}


void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
    mat->malocada[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    return mat->malocada[linha][coluna];
}

int recuperaNColunas (Matriz* mat) {
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat) {
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat) {
    Matriz* trp = inicializaMatriz(mat->ncolunas, mat->nlinhas);
     for (int i = 0 ; i<trp->nlinhas; i++) {
        for (int j = 0; j<trp->ncolunas; j++) {
            trp->malocada[i][j] = mat->malocada[j][i];
        }
    }
    return trp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
    Matriz* multiplicacao = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);
     for (int i = 0 ; i<mat1->nlinhas; i++) {
        for (int j = 0; j<mat2->ncolunas; j++) {
            for (int k = 0; k < )
        }   
    }
}


void imprimeMatriz(Matriz* mat) {
    for (int i = 0 ; i<mat->nlinhas; i++) {
        for (int j=0; j<mat->ncolunas; j++) {
            printf("%d ", mat->malocada[i][j]);
        }
        printf("\n");
    }
}