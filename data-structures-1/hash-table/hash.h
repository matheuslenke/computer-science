//
// Created by 2019202297 on 25/11/19.
//

#ifndef TABELAHASH_HASH_H
#define TABELAHASH_HASH_H
#define NPAL 40
#define NTAB 127

struct palavra {
    char pal[NPAL];
    int n;
    struct palavra* prox;
};

typedef struct palavra Palavra;

typedef Palavra* Hash[NTAB];


void InicHash (Hash tab);

int hash ( char* s);

Palavra* acessa (Hash tab, char* s);

int le_palavra (FILE* fp, char* s);

void imprime(Hash tab);

#endif //TABELAHASH_HASH_H
