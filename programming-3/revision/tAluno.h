//
// Created by lenke on 14/09/2020.
//

#ifndef REVISAO_TALUNO_H
#define REVISAO_TALUNO_H

typedef struct TAluno * tAluno;

tAluno criarAluno (char* , float );

char * obterNomeAluno(tAluno);

float obterNotaAluno(tAluno);

void destruirAluno(tAluno );

int comparaPorNomeAluno(const void*, const void*);

#endif //REVISAO_TALUNO_H
