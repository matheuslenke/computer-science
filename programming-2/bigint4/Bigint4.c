#include <stdio.h>
#include <stdlib.h>



typedef struct bigInt {
    int *n1;
    int quantidade;
}BigInt;

void soma(BigInt* numero1, BigInt* numero2) {
    BigInt* soma;
    soma = (BigInt*) malloc(sizeof(BigInt));
    soma->n1 = malloc((numero1->quantidade + numero2->quantidade)* sizeof(int));
    soma->quantidade = 0;
    int carry = 0;
    int v = 0;

    if(numero2->quantidade > numero1->quantidade) {
        // Somando digitos que n1 e n2 tem
        for(int i = 0; i < numero1->quantidade; i++) {
            v = numero1->n1[i] + numero2->n1[i] + carry;
            soma->quantidade ++;
            soma->n1[i] = v%10;
            carry = v/10;
        }
        // Somando os que n2 tem a mais
        int d = soma->quantidade;
        while (d < numero2->quantidade) {
            v = numero2->n1[d] + carry;
            soma->n1[d] = v%10;
            carry = v/10;
            d++;
            soma->quantidade++;
        }

        if(carry!=0) {
            soma->n1[d] = carry;
            d++;
            soma->quantidade++;
        }
    }

    else if(numero1->quantidade > numero2->quantidade) {
        // Somando digitos que n1 e n2 tem
        for(int i = 0; i < numero2->quantidade; i++) {
            v = numero1->n1[i] + numero2->n1[i] + carry;
            soma->quantidade ++;
            soma->n1[i] = v%10;
            carry = v/10;
        }
        // Somando os que n1 tem a mais
        int d = soma->quantidade;
        while (d < numero1->quantidade) {
            v = numero1->n1[d] + carry;
            soma->n1[d] = v%10;
            carry = v/10;
            d++;
            soma->quantidade++;
        }

        if(carry!=0) {
            soma->n1[d] = carry;
            d++;
            soma->quantidade++;
        }
    }


    else if(numero1->quantidade == numero2->quantidade) {
        // Somando digitos que n1 e n2 tem
        for(int i = 0; i < numero1->quantidade; i++) {
            v = numero1->n1[i] + numero2->n1[i] + carry;
            soma->quantidade ++;
            soma->n1[i] = v%10;
            carry = v/10;
        }
        int d = soma->quantidade;
        if(carry!=0) {
            soma->n1[d] = carry;
            d++;
            soma->quantidade++;
        }
    }

    for(int i = soma->quantidade -1; i >= 0 ; i--) {
        printf("%d", soma->n1[i]);
    }
    printf("\n");
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

        quantidade = -1;
        i=-1;
        do {
            i++;
            scanf("%c", &c1[i]);
            quantidade++;
        }while (c1[i] != '\n' && c1[i] != ' ');

//    Invertendo o vetor
        BigInt* aux2;
        aux2 = (BigInt*) malloc(sizeof(BigInt));
        aux2->n1 = malloc(quantidade * sizeof(int));
        for(int i = 0 ; i<quantidade; i++) {
            aux2->n1[quantidade - 1 - i] = c1[i] - '0';
        }
        aux2->quantidade = quantidade;

        soma(aux, aux2);

//    printf("o sucessor eh: \n");
//        for(int i = aux2.quantidade -1 ; i>=0; i--) {
//            printf("%d", aux2.n1[i]);
//        }

        return 0;


}