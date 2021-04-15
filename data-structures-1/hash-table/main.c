#include <stdio.h>
#include "hash.h"


int main(int argc, char** argv) {
    FILE* fp;
    Hash tab;
    char s[NPAL];

    if(argc != 2) {
        printf("Arquivo não encontrado \n");
        return 0;
    }

    fp = fopen(argv[1], "rt");

    if(fp == NULL) {
        printf("Erro na abertura do Arquivo!\n");
        return 0;
    }

    InicHash(tab);
    while (le_palavra(fp,s)) {
        Palavra* p = acessa(tab, s);
        p->n++;
    }

    //deve-se imprimir a tabela agora


    return 0;
}