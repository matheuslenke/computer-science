//
// Created by 2019202297 on 25/11/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hash.h"


void InicHash (Hash tab) {
    int i;
    for(i = 0; i<NTAB; i++)
        tab[i] = NULL;
}

int hash ( char* s) {
    int i;
    int total = 0;
    for(i=0; s[i] != '\0'; i++)
        total += s[i];
    return (total % NTAB);
}

Palavra* acessa (Hash tab, char* s) {
    Palavra* p;

    // Aplica função de ash
    int h = hash(s);

    // Procura na lista de colisão
    for (p = tab[h]; p!= NULL; p = p->prox) {
        if(strcmp(s, p->pal) == 0)
            return p;
    }

    // Caso não tenha encontrado na tabela, insere a nova palavra
    p = (Palavra*)malloc(sizeof (Palavra));
    strcpy(p->pal, s);
    p->n = 0;
    p->prox = tab[h];
    tab[h] = p;
    return p;
}

int le_palavra (FILE* fp, char* s) {
    int i = 0;
    int c;
    if(c == EOF) {

    }

    // Pula caracteres que não são letras
    while ((i<NPAL - 1) && (c = fgetc(fp)) != EOF && isalpha(c)) {
        s[i++] = c;
    }

    s[i] = '\0';
}

// Funçãoque cria o vetor de palavras a partir da tabela hash
int conta(Hash tab) {
    int i;
    int total=0;
    Palavra* p;
    for(i=0; i<NTAB; i++) {
        for(p = tab[i]; p!= NULL; p = p->prox) {
            total++;
        }
    }
    return total;
}
// Função que cria o vetor de palavras a partir da tabela hash
Palavra** CriaVet(Hash tab, int n) {

    int i, j=0;
    Palavra* p;
    Palavra** vet = (Palavra**)malloc(n* sizeof(Palavra*));

    // Populando o vetor
    for(i = 0; i<NTAB; i++) {
        for(p=tab[i]; p!=NULL; p = p->prox) {
            vet[j++] = p;
        }
    }
}

// Callback de comparação necessaria para usar a qsort
int compara(const void* v1, const void** v2) {
    Palavra** p1 = (Palavra**) v1;
    Palavra** p2 = (Palavra**) v2;

    if((*p1)->n > (*p2)->n)
        return -1;
    else if((*p1)->n < (*p2)->n)
        return 1;
    else
        return strcmp((*p1)->pal, (*p2)->pal);

}

void imprime(Hash tab) {
    int i,n;
    Palavra** vet;

    n = conta(tab);

    vet = CriaVet(tab, n);

    qsort(vet,n,sizeof(Palavra*),compara);

    // imprime
    for(i = 0; i<(*vet)->n; i++) {
        printf("%s\n", (*vet)->pal);
    }
}

