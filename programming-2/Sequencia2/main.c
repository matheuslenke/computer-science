#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sequencia{
    int numeros[1000];
    int quantidade;
    int repeticoes;
} tSequencia;

int main() {
    tSequencia sequencia;
    tSequencia aux, aux2;
    sequencia.quantidade = 0;
    sequencia.repeticoes = 0;
    aux.quantidade = 1;
    aux2.quantidade = 0;
    aux.repeticoes = 0;
    aux2.repeticoes = 0;
    //sequencia = (tSequencia*)malloc(sizeof(sequencia));
    int m = 0;
    int imprime = 0;
    char leitura;
    while( scanf("%d%c", &sequencia.numeros[m], &leitura) == 2 ) {
//        if(strcmp(leitura, '\n') == 0) {
//            break;
//        }
        sequencia.quantidade++;
        m++;
    }


    int naosequencia, k = 0;
    for(int i = 1; i < sequencia.quantidade; i++) {

        aux.numeros[aux.quantidade - 1] = sequencia.numeros[i-1];
        aux.quantidade = 1;
        aux.repeticoes = 1;
        while(sequencia.numeros[i] == aux.numeros[aux.quantidade - 1] + 1) {
            aux.quantidade++;
            aux.numeros[aux.quantidade -1] = sequencia.numeros[i];
            i++;
        }

        if(aux.quantidade >1) {
            int j;
            for (j = i;j<sequencia.quantidade; j++) {
                int ehrepetido = 0;
                for (int h = 0; h < aux.quantidade; h++) {
                    if (sequencia.numeros[j] != aux.numeros[h]) {
                        ehrepetido = 1;
                        break;
                    }
                    j++;
                }
                if (ehrepetido == 0) {
                    aux.repeticoes++;
                    j--;
                }
            }

            if(aux.repeticoes >= aux2.repeticoes) {
                if(aux.repeticoes == aux2.repeticoes) {
                    if(aux.quantidade >= aux2.quantidade) {
                        if(aux.quantidade == aux2.quantidade) {
                        }
                        else {

                            for(j = 0; j < aux.quantidade; j++) {
                                aux2.numeros[j] = aux.numeros[j];
                            }
                            aux2.quantidade = aux.quantidade;
                            aux2.repeticoes = aux.repeticoes;
                        }
                    }
                }
                else {

                    for(j = 0; j < aux.quantidade; j++) {
                        aux2.numeros[j] = aux.numeros[j];
                    }
                    aux2.quantidade = aux.quantidade;
                    aux2.repeticoes = aux.repeticoes;
                }

            }

        }
        aux.quantidade = 1;
    }
    if(aux2.quantidade == 0 || imprime == 1) {
        printf("0\n");
        return 0;
    }
    if(imprime == 0) {
        for(int i = 0; i < aux2.quantidade; i++) {
            printf("%d", aux2.numeros[i]);
            if(i + 1<aux2.quantidade) {
                printf(" ");
            }
        }
        printf("\n%d\n", aux2.repeticoes);
    }

    return 0;
}