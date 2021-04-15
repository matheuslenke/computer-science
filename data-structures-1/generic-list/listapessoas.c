//
// Created by Matheus Lenke on 08/12/19.
//

#include "listapessoas.h"
#include <stdlib.h>
#include <string.h>

struct listapessoas {
    ListaGen* alunos;
    ListaGen* professores;
};

struct aluno {
    char* nome;
    int cpf;
    float cr;
};

struct professor {
    char* nome;
    int cpf;
    float salario;
};

struct media {
    int n;
    float soma;
    float media;
};


tAluno* criaAluno(char nome[40], int cpf, float cr) {
    tAluno* aluno;
    aluno = (tAluno*)malloc(sizeof(tAluno));
    aluno->nome = strdup(nome);
    aluno->cpf = cpf;
    aluno->cr = cr;
    return aluno;
}
tProfessor * criaProfessor(char *nome, int cpf, float salario) {
    tProfessor* professor;
    professor = (tProfessor*)malloc(sizeof(tProfessor));
    professor->nome = strdup(nome);
    professor->cpf = cpf;
    professor->salario = salario;
    return professor;
}

ListaPessoas* leArquivo(FILE* file, ListaPessoas* pessoas) {
    pessoas = (ListaPessoas*)malloc(sizeof(ListaPessoas));
    char tipo;
    char nome[40];
    int cpf;
    float cr, salario;
    while(feof(file) == 0) {
        fscanf(file, "%c ", &tipo);
        switch(tipo) {
            case 'A': {
                fscanf(file, " %s %d %f ", nome, &cpf, &cr);
                tAluno* aluno = criaAluno(nome, cpf, cr);
                pessoas->alunos = listagen_insere(pessoas->alunos, aluno);
                break;
            }
            case 'P': {
                fscanf(file, " %s %d %f ", nome, &cpf, &salario);
                tProfessor* professor = criaProfessor(nome, cpf, salario);
                pessoas->professores = listagen_insere(pessoas->professores, professor);
                break;
            }
        }
    }
    return pessoas;
}

ListaGen* retornaAlunos(ListaPessoas* pessoas) {
    return pessoas->alunos;
}

ListaGen* retornaProfessores(ListaPessoas* pessoas) {
    return pessoas->professores;
}

static int imprimeAluno(void* info, void* dado){
    tAluno* aluno = (tAluno*) info;
    FILE* file = (FILE*) dado;
    fprintf(file, "%s, CPF: %d e CR: %.2f\n", aluno->nome, aluno->cpf, aluno->cr);
    return 0;
}
static int imprimeProfessor(void* info, void* dado){
    tProfessor* professor = (tProfessor*) info;
    FILE* file = (FILE*) dado;
    fprintf(file, "%s, CPF: %d e Salario: %.2f\n", professor->nome, professor->cpf, professor->salario);
    return 0;
}
void imprime_media_alunos(tMedia *media, FILE *file) {
    fprintf(file, "\nMedia de CR dos %d alunos: %.2f\n\n", media->n, media->media);
}
void imprime_media_professores(tMedia *media, FILE *file) {
    fprintf(file, "\nMedia de salario dos %d professores: %.2f\n\n", media->n, media->media);
}

static void libera_aluno(void* info) {
    tAluno* aux = (tAluno*)info;
    free(aux->nome);
    free(aux);
}
static void libera_professor(void* info) {
    tProfessor* aux = (tProfessor*)info;
    free(aux->nome);
    free(aux);
}

static int calcula_media_alunos(void* info, void* dado){
    tAluno* aluno = (tAluno*) info;
    tMedia* media = (tMedia*) dado;
    float* d = (float*) dado;
    media->n++;
    media->soma += aluno->cr;
    media->media = media->soma / media->n;
    return 0;
}
static int calcula_media_professores(void* info, void* dado){
    tProfessor* professor = (tProfessor*) info;
    tMedia* media = (tMedia*) dado;
    float* d = (float*) dado;
    media->n++;
    media->soma += professor->salario;
    media->media = media->soma / media->n;
    return 0;
}

tMedia* media_alunos_lista(ListaGen* lista) {
    tMedia* media = (tMedia*)malloc(sizeof(tMedia));
    media->media = 0;
    media->soma = 0;
    media->n = 0;
    listagen_percorre(lista, calcula_media_alunos, media);
    return media;
}

tMedia* media_professores_lista(ListaGen* lista) {
    tMedia* media = (tMedia*)malloc(sizeof(tMedia));
    media->media = 0;
    media->soma = 0;
    media->n = 0;
    listagen_percorre(lista, calcula_media_professores, media);
    return media;
}

void imprime_alunos(ListaGen *alunos, FILE *file) {
    fprintf(file,"ALUNOS: \n");
    listagen_percorre(alunos, imprimeAluno, file);
}
void imprime_professores(ListaGen *professores, FILE *file) {
    fprintf(file,"PROFESSORES: \n");
    listagen_percorre(professores, imprimeProfessor, file);
}

void libera_lista_pessoas(ListaPessoas* pessoas) {
    listagen_libera(pessoas->alunos, libera_aluno);
    listagen_libera(pessoas->professores, libera_professor);
    free(pessoas);
}