#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigInt {
    int n1[102];
    int quantidade;
}BigInt;

void sucessor(BigInt* aux) {
    int vaium = 0;
    int entrou = 0;
    int finalizou = 0;
    for (int i = 0; i<aux->quantidade && finalizou == 0; i++) {
        entrou = 0;
        if (aux->n1[i] == 9 && vaium==0 && entrou == 0){
            aux->n1[i] = 0;
            vaium = 1;
            entrou = 1;
        }
        if (aux->n1[i] == 9 && vaium==1 && entrou == 0 && i== aux->quantidade -1) {
            aux->n1[i] = 0;
            aux->n1[i+1] = 1;
            finalizou =1;
            entrou =1;
            aux->quantidade += 1;
        }
        if (aux->n1[i] == 9 && vaium==1 && entrou == 0 && i!= aux->quantidade -1) {
            aux->n1[i] = 0;
            entrou = 1;
        }
        if (aux->n1[i] != 9 && vaium == 0 && entrou == 0) {
            aux->n1[i] +=1;
            entrou = 1;
            finalizou = 1;
        }
        if (aux->n1[i] != 9 && vaium == 1 && entrou == 0 ) {
            entrou = 1;
            if(aux->n1[i] == 8) {
                aux->n1[i] = 0;
                vaium = 1;
            }
            else if (aux->n1[i] != 8) {
                aux->n1[i] +=1;
                finalizou = 1;
            }
        }


    }
}

int main(int argc, char const *argv[])
{
   BigInt bi1;
   bi1.quantidade = -1;
   char c1[102];
    int i=-1;
    do {
       i++;
       scanf("%c", &c1[i]);
       bi1.n1[i] = c1[i] - '0';
       bi1.quantidade++;
   }while (c1[i] != '\n' && c1[i] != ' ');

//    Invertendo o vetor
    BigInt aux;
    for(int i = 0 ; i<bi1.quantidade; i++) {
        aux.n1[bi1.quantidade - 1 - i] = bi1.n1[i];
    }
    // printf("Numero b1 ");
    // for(int i = 0; i< bi1.quantidade; i++) {
    //     printf("%d", bi1.n1[i]);
    // }
    // printf("\n");
    // printf("Numero aux: ");
     aux.quantidade = bi1.quantidade;
    // for(int i = bi1.quantidade -1; i>=0; i--) {
    //     printf("%d", aux.n1[i]);
    // }
    // printf("\n");

     sucessor(&aux);
//    printf("o sucessor eh: \n");
      for(int i = aux.quantidade -1 ; i>=0; i--) {
        printf("%d", aux.n1[i]);
    }

    return 0;
}
