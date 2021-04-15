//
// Created by 2019202297 on 17/10/19.
//

#ifndef EXERCICIOPROVA_JOGO_H
#define EXERCICIOPROVA_JOGO_H

    typedef struct {
    char nome1[30];
    int gols1;
    char nome2[30];
    int gols2;
} tJogo;

void lerJogo(tJogo *);

#endif //EXERCICIOPROVA_JOGO_H
