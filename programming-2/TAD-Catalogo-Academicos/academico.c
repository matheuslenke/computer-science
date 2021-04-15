//
// Created by 2019202297 on 31/10/19.
//

#include "academico.h"
#include <ctype.h>

#define MAX_NOME 30

struct academico {
    char* nome;
    unsigned int idade;
    unsigned int matricula;
};

tAcademico* InicializaAcademico(char* nome, unsigned int idade, unsigned int matricula) {
    tAcademico* academico;
    academico = (tAcademico*)malloc(sizeof(tAcademico*));
    academico->nome = (char*)malloc(sizeof((strlen(nome)+1 )* sizeof(char)));
    strcpy(academico->nome, nome);
    academico->idade = idade,
    academico->matricula = matricula;
}

tAcademico* leAcademico(FILE* file) {
    tAcademico* acad = (tAcademico*)malloc(sizeof(tAcademico*));
    char nome[MAX_NOME];
    fscanf(file, "%[^\n] ", nome);
    acad->nome = (char*)malloc(sizeof((strlen(nome) + 1)*sizeof(char)));
    strcpy(acad->nome, nome);
    fscanf(file, "%d ", &acad->idade);
    fscanf(file, "%u ", &acad->matricula);
    return acad;
}

int compMatricula(tAcademico* p, tAcademico* s) {
    if(p->matricula > s->matricula) return 1;
    if(p->matricula == s->matricula) return -1;
    return 0;
}
int compIdade(tAcademico* p, tAcademico* s) {
    if(p->idade > s->idade) return 1;
    if(p->idade == s->idade) return -1;
    return 0;
}
int compNome(tAcademico* p, tAcademico* s) {
    char nome1[MAX_NOME], nome2[MAX_NOME];
    strcpy(nome1, p->nome);
    char* q = nome1;
    while(*q = toupper(*q)) {
        q++;
    };
    strcpy(nome2, s->nome);
    q = nome2;
    while(*q = toupper(*q)) {
        q++;
    };
    int i = strcmp(nome1, nome2) > 0;
    return strcmp(nome1, nome2) > 0;
}

void apresentaAcademico(tAcademico* academico) {
    printf("Nome:%s idade: %u matricula: %u\n", academico->nome, academico->idade, academico->matricula);
}