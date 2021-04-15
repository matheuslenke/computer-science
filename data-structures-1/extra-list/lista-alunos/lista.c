#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

typedef struct celula TCelula;

struct aluno
{
    char *nome;
    int matricula;
};

struct lista
{
    TCelula *inicio;
    TCelula *fim;
};

struct celula
{
    TAluno *aluno;
    TCelula *prox;
};

TLista *InicializaLista()
{
    TLista *lista;
    lista = (TLista *)malloc(sizeof(TLista));
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

TAluno *InicializaAluno(char *nome, int matricula)
{
    TAluno *aluno;
    aluno = (TAluno *)malloc(sizeof(TAluno));
    // alocando valor em aluno->nome
    aluno->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(aluno->nome, nome);
    // alocando valor em aluno->matricula
    aluno->matricula = matricula;

    return aluno;
}

void InsereAluno(TLista *lista, TAluno *aluno)
{
    TCelula *celula;
    celula = (TCelula *)malloc(sizeof(TCelula));
    celula->aluno = aluno;

    if (lista->inicio == NULL)
    {
        lista->inicio = lista->fim = celula;
        celula->prox = NULL;
        return;
    }
    else
    {
        celula->prox = lista->inicio;
        lista->inicio = celula;
        return;
    }
}

TAluno *Retira(TLista *lista, int mat)
{
    TCelula *anterior;
    TAluno *auxiliar;
    anterior = NULL;

    for (TCelula *p = lista->inicio; p != NULL; p = p->prox)
    {
        // printf("Mat: %d\n", mat);
        // printf("Matricula aluno: %d", p->aluno->matricula);
        if (p->aluno->matricula == mat && p != NULL)
        {
            if(anterior != NULL) {
                anterior->prox = p->prox;
            }
            if (p == lista->fim && anterior != NULL)
            {
                lista->fim = anterior;
                auxiliar = p->aluno;
            }
            if (p == lista->fim && anterior == NULL)
            {   
                lista->inicio = NULL;
                lista->fim = NULL;
                auxiliar = p->aluno;
            }
            if (anterior = NULL)
            {
                lista->inicio = p->prox;
            }
            auxiliar = p->aluno;
            free(p);

            return auxiliar;
        }
        else if (p == lista->fim) {
            auxiliar = NULL;
            return auxiliar;
        }
        anterior = p;
    }
}

void RetiraRepetidos(TLista *lista)
{
}

TLista *Merge(TLista *turma1, TLista *turma2)
{
    TLista *merge;
    merge = InicializaLista();
    TCelula *p1, *p2, *p;

    if(turma1->inicio != NULL && turma2->inicio != NULL) {
        p1 = turma1->inicio;
        p2 = turma2->inicio;
        // printf("t1: %d | t2: %d \n", turma1->fim->aluno->matricula, turma2->fim->aluno->matricula);
        merge->inicio = turma1->inicio;
        merge->fim = turma1->inicio;
        merge->inicio->prox = merge->fim;
        p = merge->fim;
        while (p1 != turma1->fim || p2!= turma2->fim ) {
            // printf("esta caralha aqui: %d\n", p1->aluno->matricula);
            if(p1 != NULL && p1 == turma1->fim) {
                p->prox = p1;
                p = p->prox;
                merge->fim = p;
                p1 = p1->prox;   
            }
            if(p2 != NULL && p2 == turma2->fim) {
                p->prox = p2;
                p = p->prox;
                merge->fim = p;
                p2 = p2->prox;   
            }
        }
        return merge;
    }
}

void LiberaAluno(TAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

void Imprime(TLista *lista)
{

    for (TCelula *p = lista->inicio; p != NULL; p = p->prox)
    {
        printf("Aluno: %s | Matricula: %d \n", p->aluno->nome,
               p->aluno->matricula);
    }
}

void Libera(TLista *lista)
{
    for (TCelula *p = lista->inicio; p != NULL; p = p->prox) {

        free(p->aluno->nome);
        free(p->aluno);
        free(p->prox);
        free(p);
    }

}
