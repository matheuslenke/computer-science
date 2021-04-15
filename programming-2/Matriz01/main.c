#include <stdio.h>
#include <stdlib.h>


int main() {
    int m = 0; // Linhas
    int n = 0; // Colunas
    int tamanholinha = 0; // Para gravar o n de linhas pra fora do loop
    char parada; // Para saber quando um elemento termina ou quando uma linha termina
    int linha[300]; // Para gravar os arquivos da linha antes de malocar
    int **M; // Matriz dinamica
    M = malloc( 1 * sizeof(int)); // Mallocando o ponteiro da primeria linha

while(scanf("%d%c", &linha[n], &parada) == 2) {
    if(parada == ' ') {
        n++; // Incrementa mais um elemento na linha
    }
    if(parada == '\n') {
        if(m > 0) {
            M = realloc(M, (m + 1) * sizeof(int *)); // Caso precise aumentar o numero de ponteiros pra linha
        }
        M[m] = malloc(n * sizeof(int)); // Faz malloc naquela linha de acordo com o numero de elementos
        for(int h = 0; h <= n; h++) {
            M[m][h] = linha[h]; // Aloca os elementos lidos
        }
        m++; // Incrementa pra próxima linha
        tamanholinha = n; // Salva o tamanho da linha caso saia do loop
        n = 0; // Zera o tamanho da linha para ler novamente
        //i++;
    }
}
//    for(int j = 0; j < m ; j++) {
//        for(int k = 0 ; k <= tamanholinha; k++) {
//            printf("%d ", M[j][k]);
//        }
//        printf("\n");
//    }
    for(int j = 0; j <= tamanholinha ; j++) {
        for(int k = 0 ; k < m; k++) {
            printf("%d ", M[k][j]);
        }
        printf("\n");
    }


//    for (int i = 0; i < m; ++i)
//        M[i] = malloc (n * sizeof (int));

    return 0;
}