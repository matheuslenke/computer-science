#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sequencia{
    int numeros[400];
    int quantidade;
} tSequencia;

int main() {
    tSequencia sequencia;
    tSequencia aux, aux2;
    sequencia.quantidade = 0;
    aux.quantidade = 0;
    aux2.quantidade = 0;
    //sequencia = (tSequencia*)malloc(sizeof(sequencia));
    int m = 0;
    char leitura;
    while( leitura != '\n' ) {
        scanf("%d%c", &sequencia.numeros[m], &leitura);
//        if(strcmp(leitura, '\n') == 0) {
//            break;
//        }
        sequencia.quantidade++;
        m++;
    }

    for(int i = 2; i < sequencia.quantidade; i++) {
        if((sequencia.numeros[i] == (sequencia.numeros[i -1] + sequencia.numeros[i - 2])) || i >= sequencia.quantidade) {
            aux.numeros[aux.quantidade] = sequencia.numeros[i-2];
            aux.quantidade++;
            aux.numeros[aux.quantidade] = sequencia.numeros[i-1];
            aux.quantidade++;
            aux.numeros[aux.quantidade] = sequencia.numeros[i];
            aux.quantidade++;
            i++;
            while(sequencia.numeros[i] == (sequencia.numeros[i-1] + sequencia.numeros[i - 2])) {
                aux.numeros[aux.quantidade] = sequencia.numeros[i];
                aux.quantidade++;
                i++;
            }
        }

        if(aux.quantidade > aux2.quantidade) {
            for (int j = 0; j < aux.quantidade; j++) {
                aux2.numeros[j] = aux.numeros[j];
            }
        aux2.quantidade = aux.quantidade;
        }
        aux.quantidade = 0;
    }

    printf("\n%d", aux2.quantidade);

}