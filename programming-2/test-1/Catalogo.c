//
// Created by mathe on 26/10/2019.
//

#include "Catalogo.h"
#include "Produto.h"

#define DECRESCENTE 0
#define CRESCENTE 1
#define TAM_CATALOGO 20


struct catalogo {
tProduto** produtos;
int quantidade;
int tamanho_maximo;
};

tCatalogo * inicializaTipoCatalogo() {
    tCatalogo* catalogo = (tCatalogo*) malloc(TAM_CATALOGO * sizeof(struct catalogo));
    catalogo->tamanho_maximo = TAM_CATALOGO;
    catalogo->produtos = (tProduto**) malloc(TAM_CATALOGO * sizeof(tProduto*));
    return catalogo;
}
tCatalogo * incrementaCatalogo(tCatalogo *catalogo) {
    int novo_tamanho = catalogo->tamanho_maximo + 50;
    tCatalogo* aux;

    aux = (tCatalogo*) malloc(TAM_CATALOGO * sizeof(struct catalogo));
    aux->produtos = (tProduto**) malloc(novo_tamanho * sizeof(tProduto*));
    aux->tamanho_maximo = novo_tamanho;
    aux->quantidade = catalogo->quantidade;
    if(catalogo->produtos != NULL) {
        aux = copiaCatalogo(aux, catalogo);
    }
    liberaCatalogo(catalogo);
    return aux;
}
/**
 * Copia o catalogo 2 no catalogo 1
 * @param catalogo1
 * @param catalogo2
 */
tCatalogo* copiaCatalogo(tCatalogo* catalogo1, tCatalogo* catalogo2) {
    for(int i=0; i< catalogo2->quantidade; i++) {
        if(catalogo1->produtos != NULL && catalogo2->produtos != NULL) {
            catalogo1->produtos[i] = copiaProduto(catalogo1->produtos[i], catalogo2->produtos[i]);
        }
    }
    return catalogo1;
}

tCatalogo* leCatalogo(FILE* file, tCatalogo *catalogo) {
    catalogo = inicializaTipoCatalogo();
    int i = 0;
    char verificavazio[20];
    catalogo->quantidade = 0;
    catalogo->tamanho_maximo = TAM_CATALOGO;
    fscanf(file, "%s ", verificavazio );
    if(feof(file) != 0 ) return catalogo;
    rewind(file);

    catalogo->produtos[i] = leProduto(file, catalogo->produtos[i]);
    catalogo->quantidade++;
    i++;
    while(feof(file) == 0) {
        if(catalogo->quantidade >= catalogo->tamanho_maximo) {
            catalogo = incrementaCatalogo(catalogo);
        }
        catalogo->produtos[i] = leProduto(file, catalogo->produtos[i]);
        i++;
        catalogo->quantidade++;
    }
    return catalogo;
}

tCatalogo* atualizaCatalogo(FILE* file, tCatalogo* catalogo) {
    char operacao;
    char categoria[7];
    unsigned int idprocura = 0;
    unsigned int index = 0;
    char verificavazio[20];
    fscanf(file, "%s ", verificavazio );
    if(feof(file) != 0 ) return catalogo;
    rewind(file);

    while( feof(file) == 0){
        fscanf(file, "%c ", &operacao);
        switch(operacao) {
            case 'i': {
                if(catalogo->quantidade >= catalogo->tamanho_maximo) {
                    catalogo = incrementaCatalogo(catalogo);
                }
              catalogo->produtos[catalogo->quantidade] = leProduto(file, catalogo->produtos[catalogo->quantidade]);
                catalogo->quantidade++;
                break;
            }
            case 'a': {
//            fscanf(file, " %[^ \n] ", categoria);
//            fscanf(file, " %d ",  &idprocura);
//            removeChar(categoria, '\r');
            tProduto* produto = inicializaProduto();
            produto = leProduto(file, produto);
            //index = buscaIndexProduto(catalogo, retornaIdProduto(produto), catalogo->quantidade);
            //produto = buscaProduto(catalogo, idprocura, catalogo->quantidade);
            modificaProduto(catalogo, produto);
            free(produto);
                break;
            }
            case 'e': {
                tProduto* aux;
                fscanf(file, "%d ", &idprocura);
                index = buscaIndexProduto(catalogo, idprocura, catalogo->quantidade);
                for(int i = index; i < catalogo->quantidade; i++) {
                    aux = catalogo->produtos[i];
                    catalogo->produtos[i] = catalogo->produtos[i+1];
                    catalogo->produtos[i+1] = aux;
                }
                    liberaProduto(catalogo->produtos[catalogo->quantidade]);
                    catalogo->quantidade -= 1;
                break;
            }
        }
    }
    return catalogo;
}

tProduto * buscaProduto(tCatalogo *catalogo, int id, int qtd) {
    for(int i = 0; i< catalogo->quantidade; i++) {
        int id2 = retornaIdProduto(catalogo->produtos[i]);
        if(id == retornaIdProduto(catalogo->produtos[i])) {
            return catalogo->produtos[i];
        }
    }
    return 0;
}
int buscaIndexProduto(tCatalogo *catalogo, int id, int qtd) {
    for(int i = 0; i< catalogo->quantidade; i++) {
        if(id == retornaIdProduto(catalogo->produtos[i])) {
            return i;
        }
    }
    return 0;
}
void imprimeCatalogo(tCatalogo* catalogo) {
    for(int i = 0; i < catalogo->quantidade; i++) {
        imprimeIdProduto(catalogo->produtos[i]);
        printf("\n");
    }
}

void OrdenaCatalogoSpec(FILE* arq_spec, tCatalogo *catalogo) {
    int porcentagem, porcentagem2, quantidade1, quantidade2, quantidade3;
    int qtd_argilosos = 0;

    //imprimeCatalogo(catalogo);
    // Ordenação a
    tCatalogo* ordenado = inicializaTipoCatalogo();
    fscanf(arq_spec, "%d ", &porcentagem);
    if(porcentagem != 100) {
        porcentagem2 = 100 - porcentagem;
    }
    else porcentagem2 = porcentagem;
    quantidade1 = (int)((porcentagem * catalogo->quantidade)/ 100);
    ordenado->quantidade = quantidade1;
   if(ordenado->tamanho_maximo < ordenado->quantidade) {
       ordenado->produtos = NULL;
   }

    while(ordenado->tamanho_maximo < ordenado->quantidade) {
        ordenado = incrementaCatalogo(ordenado);
    }
    ordenaImoveis(catalogo, comparaMaisCaro, CRESCENTE);
    if(porcentagem != 100) {
        int count = quantidade1;
        for(int i = catalogo->quantidade; i>catalogo->quantidade - (quantidade1 +1); i--) {
            ordenado->produtos[count--] = catalogo->produtos[i];

        }

    }
    else {
        for(int i = 0; i<catalogo->quantidade; i++) {
            ordenado->produtos[i] = catalogo->produtos[i];
        }
    }
    //imprimeCatalogo(ordenado);


    // Ordenação b
    tCatalogo* argilosos_ordenado = inicializaTipoCatalogo();
    argilosos_ordenado = inicializaTipoCatalogo();

    fscanf(arq_spec, "%d ", &porcentagem);
    qtd_argilosos = calculaArgilosos(catalogo);
    if(porcentagem != 100) {
        porcentagem2 = 100 - porcentagem;
    }
    else porcentagem2 = porcentagem;
    quantidade2 = (int)((porcentagem * qtd_argilosos)/ 100);
    argilosos_ordenado->quantidade = quantidade2;

    tCatalogo* argilosos;
    argilosos = retornaArgilosos(catalogo);
    argilosos->quantidade = qtd_argilosos;
    if(argilosos_ordenado->tamanho_maximo < argilosos->quantidade) {
        argilosos_ordenado->produtos = NULL;
    }
    while(argilosos_ordenado->tamanho_maximo < argilosos->quantidade) {
        argilosos_ordenado = incrementaCatalogo(argilosos_ordenado);
    }
    ordenaArgilosos(argilosos, comparaAreaProduto, DECRESCENTE);
    int count;

    if(porcentagem2 != 100) {
         count = quantidade2-1;
        for(int i = argilosos->quantidade; i>argilosos->quantidade - quantidade2; i--) {
            argilosos_ordenado->produtos[count--] = argilosos->produtos[i-1];
        }
    }
    else {
        for(int i = 0; i<argilosos->quantidade; i++) {
            argilosos_ordenado->produtos[i] = argilosos->produtos[i];
        }
    }
    liberaCatalogo(argilosos);


    //Ordenação c
    float area_limite, preco_limite;
    fscanf(arq_spec, "%f ", &area_limite);
    fscanf(arq_spec, "%f ", &preco_limite);

    tCatalogo* lista_c = inicializaTipoCatalogo();
    lista_c = casasRefatoradas(catalogo, area_limite, preco_limite);
    //imprimeCatalogo(lista_c);
    ordenaQuartos(lista_c, comparaQtdQuartosProduto, DECRESCENTE);

    //Lendo os specs para gravaxr o arquivo saida
    int i,j,k;
    fscanf(arq_spec,"%d ", &i);
    fscanf(arq_spec,"%d ", &j);
    fscanf(arq_spec,"%d ", &k);
    i--;
    j--;
    k--;

    // Já libera os catalogos
    gravarArquivoSaida(ordenado, argilosos_ordenado, lista_c, i, j, k);
}


void ordenaImoveis(tCatalogo *catalogo, int cmp(tProduto*, tProduto*), int ordem){
    tProduto* aux;
    // Crescente
    if(ordem == 1) {
        for(int i=0; i < catalogo->quantidade ; i++) {
            for(int j=i+1; j < catalogo->quantidade; j++){
                if(cmp(catalogo->produtos[i],catalogo->produtos[j]) > 0) {
                    aux = catalogo->produtos[j];
                    catalogo->produtos[j] = catalogo->produtos[i];
                    catalogo->produtos[i] = aux;
                }
            }
        }
    }

    if(ordem == 0) {
        for(int i=0; i < catalogo->quantidade ; i++) {
            for(int j=i+1; j < catalogo->quantidade; j++){
                if(cmp(catalogo->produtos[i],catalogo->produtos[j]) <= 0) {
                        aux = catalogo->produtos[j];
                        catalogo->produtos[j] = catalogo->produtos[i];
                        catalogo->produtos[i] = aux;
                }
            }
        }
    }
}

int calculaArgilosos(tCatalogo *catalogo) {
    int qtd_argilosos = 0;
    for(int i = 0; i< catalogo->quantidade; i++) {
        if(ehProdutoArgiloso(catalogo->produtos[i]) == 1) {
            qtd_argilosos++;
        }
    }
    return qtd_argilosos;
}

tCatalogo * retornaArgilosos(tCatalogo *catalogo) {
    tCatalogo* Aux;
    Aux = inicializaTipoCatalogo();
    Aux->quantidade = 0;
    for(int i = 0; i< catalogo->quantidade; i++) {
        if(ehProdutoArgiloso(catalogo->produtos[i])) {
            if(Aux->tamanho_maximo < Aux->quantidade) {
                Aux = incrementaCatalogo(Aux);
            }
           Aux->produtos[Aux->quantidade]= catalogo->produtos[i];
           Aux->quantidade++;
        }
    }
    return Aux;
}

void ordenaArgilosos(tCatalogo *catalogo, int cmp(tProduto *, tProduto *), int ordem){
    tProduto* aux;
    // Crescente
    if(ordem == 1) {
        for(int i=0; i < catalogo->quantidade ;i++) {
            for(int j=i+1; j < catalogo->quantidade;j++){
                if(cmp(catalogo->produtos[i],
                       catalogo->produtos[j]) > 0){
                        aux = catalogo->produtos[j];
                        catalogo->produtos[j] = catalogo->produtos[i];
                        catalogo->produtos[i] = aux;


                }
            }
        }
    }
    // Decrescente
    else {
        for(int i=0; i < catalogo->quantidade ;i++) {
            for(int j=i+1; j < catalogo->quantidade;j++){
                if(cmp(catalogo->produtos[i],
                       catalogo->produtos[j]) < 0){
                        aux = catalogo->produtos[j];
                        catalogo->produtos[j] = catalogo->produtos[i];
                        catalogo->produtos[i] = aux;
                }
            }
        }
    }
}

tCatalogo * casasRefatoradas(tCatalogo *catalogo, float area_limite, float preco_limite) {
    tCatalogo* aux;
    aux = inicializaTipoCatalogo();
    aux->quantidade = 0;
    for(int i = 0; i< catalogo->quantidade; i++) {
        if(ehProdutoEspec(catalogo->produtos[i], area_limite, preco_limite) == 1) {
            if(aux->tamanho_maximo < aux->quantidade) {
                aux = incrementaCatalogo(aux);
            }
            aux->produtos[aux->quantidade] = copiaProduto(aux->produtos[aux->quantidade], catalogo->produtos[i]);
            //aux->produtos[aux->quantidade] = catalogo->produtos[i];
            aux->quantidade++;
        }
    }
    return aux;
}

void ordenaQuartos(tCatalogo *catalogo, int cmp(tProduto*, tProduto*, int), int ordem) {
    tProduto* aux;
    if (ordem == 1) {
        for (int i = 0; i < catalogo->quantidade; i++) {
            for (int j = i +1 ; j < catalogo->quantidade; j++) {
                if (cmp(catalogo->produtos[i],
                        catalogo->produtos[j], ordem) > 0) {
                        aux = catalogo->produtos[j];
                        catalogo->produtos[j] = catalogo->produtos[i];
                        catalogo->produtos[i] = aux;

                }

            }
        }
    }
    else if (ordem == 0) {
        for (int i = 0; i < catalogo->quantidade; i++) {
            for (int j = i+1; j < catalogo->quantidade; j++) {
                if (cmp(catalogo->produtos[i],
                        catalogo->produtos[j], ordem) < 0) {
                        aux = catalogo->produtos[j];
                        catalogo->produtos[j] = catalogo->produtos[i];
                        catalogo->produtos[i] = aux;

                }

            }
        }
    }
}


void gravarArquivoSaida (tCatalogo *catalogo1, tCatalogo *catalogo2, tCatalogo *catalogo3, int i,
                         int j, int k) {
//    FILE* saida;
//    saida = fopen("../saida.txt", "w");
    int quantidade1 = catalogo1->quantidade;
    int quantidade2 = catalogo2->quantidade;
    int quantidade3 = catalogo3->quantidade;
    unsigned int saida1 = 0;
    if ((i > catalogo1->quantidade || i < 0) && (j > catalogo2->quantidade || j< 0) && (k >
    catalogo3->quantidade || k< 0)) {
        printf( "%u", saida1);
        printf( "\n");
        return;
    }

    if(i < catalogo1->quantidade && i>= 0) {
        saida1 += retornaIdProduto(catalogo1->produtos[i]);
    }
    if(j < catalogo2->quantidade && j>= 0) {
        saida1 += retornaIdProduto(catalogo2->produtos[j]);
    }
    if(k < catalogo3->quantidade && k>= 0) {
        saida1 += retornaIdProduto(catalogo3->produtos[k]);
    }
    printf("%u", saida1);
    printf( "\n");

    if(catalogo1->quantidade > 0 )
    for(int i = 0; i<catalogo1->quantidade; i++) {
        printf("%u", retornaIdProduto(catalogo1->produtos[i]));
        if(i != catalogo1->quantidade -1 ) printf( ", ");
    }
    printf("\n");

    for(int i = 0; i<catalogo2->quantidade; i++) {
        printf("%u", retornaIdProduto(catalogo2->produtos[i]));
        if(i != catalogo2->quantidade -1) printf(", ");
    }
    printf( "\n");

    for(int i = 0; i<catalogo3->quantidade; i++) {
        printf("%u", retornaIdProduto(catalogo3->produtos[i]));
        if(i != catalogo3->quantidade -1) printf( ", ");
    }
    printf("\n");

    liberaCatalogo(catalogo1);
    liberaCatalogo(catalogo2);
    liberaCatalogo(catalogo3);
//    fclose(saida);
}

void modificaProduto(tCatalogo* catalogo, tProduto* produto) {
    int id = retornaIdProduto(produto);
    for(int i = 0; i< catalogo->quantidade; i++) {
        if(id == retornaIdProduto(catalogo->produtos[i])) {
            catalogo->produtos[i] = copiaProduto(catalogo->produtos[i], produto);
            break;
        }
    }
}

void liberaCatalogoTodo(tCatalogo *catalogo) {
    for(int i = 0; i< catalogo->quantidade; i++) {
        liberaProduto(catalogo->produtos[i]);
    }
    free(catalogo->produtos);
    free(catalogo);
}

void liberaCatalogo (tCatalogo* catalogo) {
    free(catalogo->produtos);
    free(catalogo);
}
