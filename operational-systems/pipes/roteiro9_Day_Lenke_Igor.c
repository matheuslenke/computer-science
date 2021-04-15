#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define DATA "Meu filho, crie e envie para o seu irmão um array de números inteiros com valores randômicos entre 1 e o valor enviado anteriormente. O tamanho do array também deve ser randômico, na faixa de 1 a 10"

void erro_leitura(int codigo) {
    printf("Erro ao ler dado! codigo %d\n", codigo);
}
void erro_escrita(int codigo) {
    printf("Erro ao escrever dado! codigo %d\n", codigo);
}

int main (int argc, char* agrv[]) {
    // Pipe 1
    int pipe1[2], pipe2[2], pipe3[2];
    if(pipe(pipe1) == -1) {
        printf("Erro ao abrir o pipe\n");
        return 1;
    }
    if(pipe(pipe2) == -1) {
        printf("Erro ao abrir o pipe\n");
        return 1;
    }
    if(pipe(pipe3) == -1) {
        printf("Erro ao abrir o pipe\n");
        return 1;
    }
    int pid = fork();
    if(pid == -1) {
        printf("Erro ao fazer fork\n");
        return 2;
    }

    if (pid == 0) {
        // Child Process P1
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe3[0]);
        close(pipe3[1]);
        
        int x;
        if(read(pipe1[0], &x, sizeof(int)) == -1) { erro_leitura(3); return 3;}
        printf("[P1] Valor lido: %d\n", x);

        // Lendo a mensagem
        int n;
        char* string;
        if(read(pipe1[0], &n, sizeof(int)) == -1) { erro_leitura(4); return 4; }
        // printf("[P1] Tamanho da string: %d\n", n);
        string = (char*)malloc(sizeof(char) * (n + 1));
        if(read(pipe1[0], string, sizeof(char) * n) == -1) { erro_leitura(5); return 5; }
        printf("[P1] %s\n", string);

        // Gerando array randômico
        srand(time(NULL));
        int tamanhoArray = rand() % 10 + 1; // Array de tamanho entre 1 e 10
        int arr[tamanhoArray];

        // Gera números entre 1 e X
        printf("[P1] Array gerado: \n");
        for(int i = 0; i < tamanhoArray; i++) {
            arr[i] = rand() % x + 1;
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Mandar o array de P1 Para P2
        if(write(pipe2[1], &tamanhoArray, sizeof(int)) < 0) { erro_escrita(6); return 6;}
        if(write(pipe2[1], arr, sizeof(int) * tamanhoArray) < 0) { erro_escrita(7); return 7; }

        close(pipe1[0]);
        close(pipe2[1]);
        free(string);
    } else  {
        // Parent Process
        close(pipe1[0]);
        int x;
        printf("[P0] Digite um inteiro entre 1 e 5: ");
        scanf("%d", &x);
        while(x < 1 || x > 5) {
            printf("[P0] Digite um valor válido\n");
            printf("[P0] Digite um inteiro entre 1 e 5: ");
            scanf("%d", &x);
        }
        // Enviando X
        if(write(pipe1[1], &x, sizeof(int)) == -1) { erro_escrita(8); return 8; }
        // Enviando a mensagem
        char* string = strdup(DATA);
        int n = strlen(string);
        if(write(pipe1[1], &n, sizeof(int)) == -1) { erro_escrita(9); return 9; }
        if(write(pipe1[1], string, sizeof(char) * n) == -1) {erro_escrita(10); return 10;}

        // Criando o processo P2
        int pid2 = fork();
        if(pid2 < 0) { printf("Erro ao criar P2\n"); return 11;}
        if(pid2 == 0) {
            // P2
            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe3[0]);
            int size;
            int sum = 0;
            if(read(pipe2[0], &size, sizeof(int)) == -1) { erro_leitura(12); return 12; }
            int arr[size];
            if(read(pipe2[0], arr, sizeof(int) * size) < 0) { erro_leitura(13); return 13; }
            printf("[P2] Array recebido com %d elementos: \n", size);
            printf("| ");
            for(int i = 0; i < size; i++) {
                printf("%d | ", arr[i]);
                sum += arr[i];
            }
            printf("\n");
            if(write(pipe3[1], &sum, sizeof(int)) == -1) { erro_escrita(14); return 14; }
            close(pipe2[0]);
            close(pipe3[1]);
        } else {
            // Continuação do processo Pai
            close(pipe3[1]);
            int sum;
            if(read(pipe3[0], &sum, sizeof(int)) == -1) { erro_leitura(15); return 15; }
            printf("[P0] O resultado da soma é: %d\n", sum);
            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe2[0]);
            close(pipe3[0]);
            free(string);
        }
    }
    return 0;
}