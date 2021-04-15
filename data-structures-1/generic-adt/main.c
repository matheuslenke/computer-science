#include <stdio.h>
#include "lpontos.h"
int main() {

    TipoPonto* p1 = cria_ponto(1.2, 2.4);
    TipoPonto* p2 = cria_ponto(3.2, 5.3);
    TipoPonto* p3 = cria_ponto(2.2, 6.1);
    TipoPonto* p4 = cria_ponto(8.2, 3.0);
    TipoPonto* p5 = cria_ponto(6.2, 4.2);
//    TipoPonto* p6 = cria_ponto(6.515, 4.2);


    ListaGen* listapontos;
    listapontos = insere_ponto(listapontos, p1);
    listapontos = insere_ponto(listapontos, p2);
    listapontos = insere_ponto(listapontos, p3);
    listapontos = insere_ponto(listapontos, p4);
    listapontos = insere_ponto(listapontos, p5);

    imprime_pontos(listapontos);

    listapontos = retira_ponto(listapontos, p1);
    printf("\n Retirando o ponto 5 \n");
    imprime_pontos(listapontos);

    CG* centro = centro_geometrico_lista(listapontos);
    imprime_CG(centro);

    int a = pertence(listapontos, p2);
    printf("p2 pertence? %d \n", a);
    int b = pertence(listapontos, p1);
    printf("p1 pertence? %d \n", b);

    return 0;
}