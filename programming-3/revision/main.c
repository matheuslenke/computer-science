#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAluno.h"

int main(int argc, char **argv) {
    FILE * file;
    char *nomeArquivo;
    char linha[255];

    if(argc > 1) {
        nomeArquivo = argv[1];
    }

    else {
        nomeArquivo = (char*) malloc(255 * sizeof(char));
        printf("Digite o nome do arquivo que deseja abrir: \n");
        scanf("%s", nomeArquivo);
    }

    file = fopen(nomeArquivo, "r");

    if(!file){
        printf("Erro ao abrir arquivo! %s", nomeArquivo);
        return -1;
    }
    printf("Nome do arquivo: %s\n", nomeArquivo);

    int numAlunos = 0;
    fscanf(file, "%d\n", &numAlunos);

    char nome[50];
    float nota;
    int idx = 0;
    tAluno * alunos = (tAluno*)malloc(numAlunos * sizeof(tAluno));

    while(fgets(linha, sizeof(linha), file)) {
        linha[strlen(linha) - 1] = '\0';
        sscanf(linha, "%f %s", &nota, nome);
        alunos[idx++] = criarAluno(nome, nota);
    }
    fclose(file);

    qsort(alunos, numAlunos, sizeof(tAluno), comparaPorNomeAluno);

    float media = 0;
    for( idx = 0; idx < numAlunos; idx ++) {
        media += obterNotaAluno(alunos[idx]);
    }

    media /= numAlunos;

    printf("A média da turma foi: %.2f\n", media);

    for( idx = 0; idx < numAlunos; idx ++) {
        printf("Aluno %s tirou %.2f\n", obterNomeAluno(alunos[idx]), obterNotaAluno(alunos[idx]));
    }

    printf("\n\nAlunos acima da média: (%.2f)\n", media);
    for( idx = 0; idx < numAlunos; idx ++) {
        nota = obterNotaAluno(alunos[idx]);
        if(nota >= media) {
            printf("Aluno %s (%.2f)\n", obterNomeAluno(alunos[idx]), obterNotaAluno(alunos[idx]));
        }
    }

    file = fopen("saida.csv", "w");
    fprintf(file, "Nome,Nota,Situação\n");
    for( idx = 0; idx < numAlunos; idx ++) {
        nota = obterNotaAluno(alunos[idx]);
        char * aluno = obterNomeAluno(alunos[idx]);

        if(nota >= 7.0) {
            fprintf(file,"%s,%.2f,Aprovado\n", aluno, nota);
        } else {
            fprintf(file,"%s,%.2f,Prova Final\n", nome, nota);
        }
    }
    for( idx = 0; idx < numAlunos; idx ++) {
        destruirAluno(alunos[idx]);
    }

    return 0;
}
