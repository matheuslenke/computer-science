//
// Created by Matheus Lenke on 20/11/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigInt {
    unsigned int n1[102];
    int quantidade;
}BigInt;

void soma(BigInt numero1, BigInt numero2) {
    BigInt mult;
    mult.quantidade = 0;
    unsigned int carry = 0;
    unsigned int v = 0;
    int d = 0;

        for(int j = 0; j < numero2.quantidade; j++) {
            carry = 0;
            for(int i = 0; i< numero1.quantidade; i++) {
                v = numero2.n1[j] * numero1.n1[i] + carry;
                if(d > i + j) {
                    v+=mult.n1[i+j];
                }
                mult.n1[i+j] = v%10;
                carry = v/10;
                if(d< i+j+1) {
                    d = i+ j + 1;
                }
            }
            if(carry) {
                mult.n1[d] = carry;
                d++;
            }
        }

       mult.quantidade = d;
        int ehzero = 0;
    for(int i = 0; i<mult.quantidade; i++){
        if(mult.n1[i] != 0) {
            ehzero = 1;
        }
    }

    if(ehzero == 0) {
        printf("0");
        return;
    }

    for(int i = mult.quantidade -1; i >= 0 ; i--) {
        printf("%d", mult.n1[i]);
    }
   // printf("\n");
}

int main() {
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
    aux.quantidade = bi1.quantidade;

    unsigned int numero2;
    scanf("%ud", &numero2);
    BigInt bi2;
    bi2.quantidade = 1;
    bi2.n1[0] = numero2;
//    bi2.quantidade = -1;
//    i=-1;
//    do {
//        i++;
//        scanf("%c", &c1[i]);
//        bi2.n1[i] = c1[i] - '0';
//        bi2.quantidade++;
//    }while (c1[i] != '\n' && c1[i] != ' ');
//
////    Invertendo o vetor
//    BigInt aux2;
//    for(int i = 0 ; i<bi2.quantidade; i++) {
//        aux2.n1[bi2.quantidade - 1 - i] = bi2.n1[i];
//    }
//    aux2.quantidade = bi2.quantidade;
//

    if(aux.quantidade >= bi2.quantidade) {
        soma(aux, bi2);
    }
    else {
        soma(bi2, aux);
    }



//    printf("o sucessor eh: \n");
//        for(int i = aux2.quantidade -1 ; i>=0; i--) {
//            printf("%d", aux2.n1[i]);
//        }

    return 0;


}