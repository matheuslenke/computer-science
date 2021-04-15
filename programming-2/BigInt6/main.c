
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigInt {
    unsigned int n1[150];
    int quantidade;
}BigInt;

void fatorial(unsigned int numero) {

    if(numero == 0) {
        printf("1");
        return;
    }
    BigInt fatorial;
    for(int i = 0; i< 150; i++) {
        fatorial.n1[i] = 0;
    }
    BigInt numero1, numero2;
    numero1.n1[0] = 1;
    numero1.quantidade = 1;
    numero2.quantidade = 1;
    fatorial.quantidade = 1;
    fatorial.n1[0] = 1;
    unsigned int carry = 0;
    unsigned int v = 0;
    int d = 0;
    for(int k = 2; k <= numero; k++) {
    numero2.quantidade = 1;
    numero2.n1[0] = k;
    numero1.quantidade = fatorial.quantidade;
    for(int h = 0; h<fatorial.quantidade; h++) {
        numero1.n1[h] = fatorial.n1[h];
        fatorial.n1[h] = 0;
    }
    fatorial.quantidade = 0;
    fatorial.n1[0] = 0;
        for (int j = 0; j < numero2.quantidade; j++) {
            carry = 0;
            for (int i = 0; i < numero1.quantidade; i++) {
                v = numero2.n1[j] * numero1.n1[i] + carry;
                if (d > i + j) {
                    v += fatorial.n1[i + j];
                }
                fatorial.n1[i + j] = v % 10;
                carry = v / 10;
                if (d < i + j + 1) {
                    d = i + j + 1;
                }
            }
            if (carry) {
                if(carry >= 10) {
                    while(carry >= 10) {
                        fatorial.n1[d] = carry%10;
                        carry = carry/10;
                        d++;
                    }

                }
                if(carry) {
                    fatorial.n1[d] = carry;
                    d++;
                }

            }

        }
            fatorial.quantidade = d;
    }

    int ehzero = 0;
    for(int i = 0; i<fatorial.quantidade; i++){
        if(fatorial.n1[i] != 0) {
            ehzero = 1;
            break;
        }
    }

    if(ehzero == 0) {
        printf("0");
        return;
    }

    for(int i = fatorial.quantidade -1; i >= 0 ; i--) {
        printf("%d", fatorial.n1[i]);
    }
    // printf("\n");
}
int main() {
    unsigned int numero;
   scanf("%ud", &numero);
   if(numero > 70) {
       return 0;
   }
   fatorial(numero);
}