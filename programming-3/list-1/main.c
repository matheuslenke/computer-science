#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"

typedef struct talunos {
    tAluno** alunos;
    int quantidade;
}tAlunos;

void imprimeSituacao(tAluno** alunos, int quantidade) {
    FILE* saida = fopen("saida.csv", "w");

    for(int i = 0; i < quantidade; i ++) {
        float nota = retornaNota(alunos[i]);
        char* nome = retornaNome(alunos[i]);
        if( nota >= 7) {
            fprintf(saida,"%s,%.2f,Aprovado\n", nome , nota);
        }
        else {
            fprintf(saida,"%s,%.2f,Prova Final\n", nome, nota);
        }
    }
}

int main(int argc, char *argv[ ]) {
    FILE* file;
    if(argc <=1) {
        char* nomearquivo;
        nomearquivo = (char*) malloc(256 * sizeof(char));
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomearquivo);


        file = fopen(nomearquivo, "r");

        char buffer[300];
        int linhas = 0;
        while (feof(file) == 0) {
            fscanf(file,"%[^\n]", buffer);
            fgetc(file);
            linhas ++;
        }
        rewind(file);

        char nome[100];
        char aux[10];
        float nota;
        tAluno** alunos;
        alunos = (tAluno**) malloc((linhas + 1) * sizeof(tAluno*));
        int quantidade = 0;


        char stop = '0'; /**< Caracter que define o critério de parada da leitura */
        do {
            int a = feof(file);
            fscanf(file,"\n%[^,]",  nome);

            fscanf(file,",%[^\n]", aux);
            fgetc(file);
            nota = (float) atof(aux);
            alunos[quantidade] = leAluno(nome, nota);
            imprimeAluno(alunos[quantidade]);
            quantidade ++;

        } while(feof(file) == 0);

        // Ordenando o vetor
        ordenaAlunos(alunos, quantidade);

        // Calculando a media
        float media;
        media = calculaMedia(alunos,quantidade);

        printf("A media da turma é: %.1f\n", media);
        printf("\n\n\nImprimindo agora apenas os acimas da media: \n");
        for(int i = 0; i < quantidade; i++) {
            if(retornaNota(alunos[i]) >= media) {
                imprimeAluno(alunos[i]);
            }
        }

        // Imprimindo no arquivo no final

        imprimeSituacao(alunos, quantidade);

    }

    else {
        file = fopen(argv[0], "r");
        printf("O nome do arquivo é: %s", argv[0]);
    }

    if(file == NULL) {
        printf("Falha na abertura do arquivo");
    }

    return 0;
}
