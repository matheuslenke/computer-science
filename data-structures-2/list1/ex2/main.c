#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "josefo.h"

int main() {
    int N;
    int M;
    printf("Digite um número N de pessoas:");
    scanf("%d", &N);
    printf("Digite um número M para eliminar a M-esima pessoa:");
    scanf("%d", &M);

    TipoLista* circulo = criaCirculo(N);
    encontraLider(circulo, M);
    Libera(circulo);
    liberaCirculo(circulo);
    free(circulo);

}
