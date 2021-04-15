#include <stdio.h>
#include <stdlib.h>

typedef struct bigInt {
    int *n1;
    int quantidade;
}BigInt;

void soma(BigInt* numero1, BigInt* numero2) {
    BigInt* mult;
    mult = (BigInt*) malloc(sizeof(BigInt));
    mult->n1 = malloc((numero1->quantidade + numero2->quantidade) * sizeof(int));
    mult->quantidade = 0;
    unsigned int carry = 0;
    unsigned int v = 0;
    int d = 0;

    for(int j = 0; j < numero2->quantidade; j++) {
        carry = 0;
        for(int i = 0; i< numero1->quantidade; i++) {
            v = numero2->n1[j] * numero1->n1[i] + carry;
            if(d > i + j) {
                v+=mult->n1[i+j];
            }
            mult->n1[i+j] = v%10;
            carry = v/10;
            if(d< i+j+1) {
                d = i+ j + 1;
            }
        }
        if(carry) {
            mult->n1[d] = carry;
            d++;
        }
    }

    mult->quantidade = d;
    int ehzero = 0;
    for(int i = 0; i<mult->quantidade; i++){
        if(mult->n1[i] != 0) {
            ehzero = 1;
        }
    }

    if(ehzero == 0) {
        printf("0");
        return;
    }

    for(int i = mult->quantidade -1; i >= 0 ; i--) {
        printf("%d", mult->n1[i]);
    }
    // printf("\n");
}

int main() {
    int quantidade = -1;
        char c1[3000];
        int i=-1;
        do {
            i++;
            scanf("%c", &c1[i]);
            quantidade++;
        }while (c1[i] != '\n' && c1[i] != ' ');
//    bi1.n1[i] = c1[i] - '0';
//    bi1.quantidade++;
//    Invertendo o vetor
        BigInt* aux;
        aux = (BigInt*) malloc(sizeof(BigInt));
        aux->n1 = malloc(quantidade * sizeof(int));
        for(int i = 0 ; i<quantidade; i++) {
            aux->n1[quantidade - 1 - i] = c1[i] - '0';
        }
        aux->quantidade = quantidade;

//        quantidade = -1;
//        i=-1;
//        do {
//            i++;
//            scanf("%c", &c1[i]);
//            quantidade++;
//        }while (c1[i] != '\n' && c1[i] != ' ');
//
////    Invertendo o vetor
//        BigInt* aux2;
//        aux2 = (BigInt*) malloc(sizeof(BigInt));
//        aux2->n1 = malloc(quantidade * sizeof(int));
//        for(int i = 0 ; i<quantidade; i++) {
//            aux2->n1[quantidade - 1 - i] = c1[i] - '0';
//        }
//        aux2->quantidade = quantidade;

    unsigned int numero2;
    scanf("%ud", &numero2);
    BigInt* aux2;
    aux2 = (BigInt*)malloc(sizeof(BigInt));
    aux2->n1 = malloc(2 * sizeof(unsigned int));
    aux2->quantidade = 1;
    aux2->n1[0] = numero2;

    if(aux->quantidade >= aux2->quantidade) {
        soma(aux, aux2);
    }
    else {
        soma(aux2, aux);
    }

    return 0;
}