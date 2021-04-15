//
// Created by Matheus Lenke on 08/12/19.
//

#ifndef PROVA1_LISTAPESSOAS_H
#define PROVA1_LISTAPESSOAS_H

#include "listagen.h"
#define PROFESSORES 0
#define ALUNOS 1


typedef struct listapessoas ListaPessoas;

typedef struct aluno tAluno;

typedef struct professor tProfessor;

typedef struct media tMedia;

tAluno* criaAluno(char nome[40], int cpf, float cr);

tProfessor * criaProfessor(char *nome, int cpf, float salario);

ListaPessoas* leArquivo(FILE* file, ListaPessoas* pessoas);

ListaGen* retornaAlunos(ListaPessoas* pessoas);

ListaGen* retornaProfessores(ListaPessoas* pessoas);

tMedia* media_alunos_lista(ListaGen* lista);

tMedia* media_professores_lista(ListaGen* lista);

void imprime_media_alunos(tMedia *media, FILE *file);

void imprime_media_professores(tMedia *media, FILE *file);

void imprime_alunos(ListaGen *alunos, FILE *file);

void imprime_professores(ListaGen *professores, FILE *file);

void libera_lista_pessoas(ListaPessoas* pessoas);

static int imprime(void* info, void* dado);

static int imprimeProfessor(void* info, void* dado);

static int imprimeAluno(void* info, void* dado);

static int calcula_media_alunos(void* info, void* dado);

static int calcula_media_professores(void* info, void* dado);

static void libera_aluno(void* info);

static void libera_professor(void* info);
#endif //PROVA1_LISTAPESSOAS_H
