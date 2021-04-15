//
// Created by mathe on 27/10/2019.
//

#include "Produto.h"
#include "Imovel.h"

struct produto {
    tImovel* imovel;
    char* categoria;
    unsigned int id;
    char* proprietario;
    float areatotal;
};

tProduto * inicializaProduto() {
    tProduto* produto= (tProduto*)malloc(sizeof(tProduto));
    produto->imovel = (tImovel*)malloc(sizeof(tImovel*));
    return produto;
}

tProduto* copiaProduto(tProduto* produto1, tProduto* produto2) {
    if(produto2 != NULL) {
        produto1 = inicializaProduto();
        produto1->categoria = produto2->categoria;
        produto1->id = produto2->id;
        produto1->imovel = produto2->imovel;
        produto1->proprietario = produto2->proprietario;
        produto1->areatotal = produto2->areatotal;
    }
    return produto1;
}

void imprimeIdProduto(tProduto* produto) {
    printf("%d", produto->id);
}

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

tProduto* leProduto(FILE* file, tProduto *produto) {
    char stop;
    char proprietario[100], categoria[50];
    produto = inicializaProduto();

    fscanf(file, "%[^\n] ", categoria);
    //stop = fgetc(file);
    removeChar(categoria, '\r');

    produto->categoria = (char*) malloc((strlen(categoria)+1)* sizeof(char));
    strcpy(produto->categoria,categoria);
    fscanf(file, " %u ", &produto->id);
    //stop = fgetc(file);

    fscanf(file, "%[^\n] ", proprietario);
    removeChar(proprietario, '\r');

    produto->proprietario = (char*)malloc((strlen(proprietario)+ 1) * sizeof(char));
    strcpy(produto->proprietario, proprietario);

    produto->imovel = leImovel(file, produto->imovel, produto->categoria);
    //fscanf(file, " %[^\n] ", stop);
  //  calculaPrecoProduto(produto, produto->categoria);

  return produto;
}


tProduto* alteraProduto(FILE* file, tProduto *produto, char *categoria) {
    produto->categoria = strdup( categoria);
    char nome[100];
    fscanf(file, "%[^\n] ", nome);
    produto->proprietario = (char*) malloc((strlen(nome)+1) * sizeof(char));
    strcpy(produto->proprietario, nome);
    removeChar(produto->proprietario, '\r');

    produto->imovel = atualizaImovel(file, produto->imovel, categoria);
    return produto;
}

void trocaPosicaoProduto(tProduto *produto1, tProduto *produto2) {
    tProduto* aux;
    aux = produto1;
    produto1 = produto2;
    produto2 = aux;
}

int comparaMaisCaro(tProduto *produto1, tProduto *produto2){
    int aux;
    aux = comparaPrecoImovel(produto1->imovel, produto2->imovel);
    if(aux == 0) {
        if(produto1->id > produto2->id){
            aux = 1;
        }
        else aux = -1;
    }
    return aux;
}


int ehProdutoEspec(tProduto *produto, float area_limite, float preco_limite) {
    if(ehCasaEspecifica(produto->imovel, area_limite, preco_limite ) == 1) {
        return 1;
    }
    else return 0;
}

int comparaQtdQuartosProduto(tProduto *produto1, tProduto *produto2, int ordem) {
    int aux = comparaQtdQuartos(produto1->imovel, produto2->imovel);
    if (aux == 0) {
        if(ordem == 0) {
            if(produto1->id > produto2->id) {
                aux = 1;
            }
            else aux = -1;
        }
        else {
            if(produto1->id < produto2->id) {
                aux = 1;
            }
            else aux = -1;
        }

    }
    return aux;
}

int ehProdutoArgiloso(tProduto *produto) {
    if(strcmp(produto->categoria, "retang") == 0 || strcmp(produto->categoria, "trapez") == 0 || strcmp(produto->categoria, "triang") == 0) {
        return ehImovelArgiloso(produto->imovel);
    }
    else return 0;
}
int retornaIdProduto(tProduto *produto) {
    return produto->id;
}

int comparaAreaProduto(tProduto *produto1, tProduto *produto2) {
    int aux = comparaAreaImovel(produto1->imovel, produto2->imovel);
    if(aux == 0) {
        if(produto2->id > produto1->id) {
            return 1;
        }
    }
    return aux;
}

void liberaProduto(tProduto* produto) {
    liberaImovel(produto->imovel);
    free(produto->categoria);
    free(produto->proprietario);
    free(produto);
}