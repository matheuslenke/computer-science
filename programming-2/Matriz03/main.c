#include <stdio.h>
#include <stdlib.h>


int main() {
    int m = 0;
    int n = 0;
    int tamanholinha = 0;
    int numero;
    char parada;
    int linha[300];
    int **M;
    int i=0;
    M = malloc( 1 * sizeof(int));
    while(scanf("%d%c", &linha[n], &parada) == 2) {
        if(parada == ' ') {
            n++;
        }
        if(parada == '\n') {

            if(i > 0) {
                M = realloc(M, (m + 1) * sizeof(int *));
            }
            M[m] = malloc(n * sizeof(int));
            for(int h = 0; h <= n; h++) {
                M[m][h] = linha[h];
            }
            m++;
            tamanholinha = n;
            n = 0;
            i++;
        }
    }
//    for(int j = 0; j < m ; j++) {
//        for(int k = 0 ; k <= tamanholinha; k++) {
//            printf("%d ", M[j][k]);
//        }
//        printf("\n");
//    }
    int soma = 0;
    int ehisolado = 0;
    for(int j = 0; j < m ; j++) {
        for(int k = 0 ; k <= tamanholinha; k++) {
            if(M[j][k] == 1) {
                    // Na linha de cima
                    if(j - 1 >= 0) {
                        if(k -1 >=0) {
                            if (M[j-1][k-1] == 1) {
                                ehisolado = 1;
                            }
                        }
                        if (M[j-1][k] == 1) {
                            ehisolado = 1;
                        }
                        if(k +1 <= tamanholinha) {
                            if (M[j-1][k+1] == 1) {
                                ehisolado = 1;
                            }
                        }
                    }

                    // Na própria linha
                    if(k -1 >=0) {
                        if (M[j][k-1] == 1) {
                            ehisolado = 1;
                        }
                    }
                    if(k + 1 <= tamanholinha) {
                        if (M[j][k+1] == 1) {
                            ehisolado = 1;
                        }
                    }
                    // Na linha abaixo
                    if(j+1 < m) {
                        if(k -1 >=0) {
                            if (M[j+1][k-1] == 1) {
                                ehisolado = 1;
                            }
                        }
                        if (M[j+1][k] == 1) {
                            ehisolado = 1;
                        }
                        if(k +1 <= tamanholinha) {
                            if (M[j+1][k+1] == 1) {
                                ehisolado = 1;
                            }
                        }
                    }

                if(ehisolado == 0) {
                    soma++;
                }
                ehisolado = 0;
            }
        }
    }

    printf("%d", soma);

//    for (int i = 0; i < m; ++i)
//        M[i] = malloc (n * sizeof (int));

    return 0;
}