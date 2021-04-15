//
// Created by 2019202297 on 18/11/19.
//

#ifndef ARVVAR_ARVVAR_H
#define ARVVAR_ARVVAR_H

typedef struct arvvar ArvVar;

ArvVar* arvv_cria(char info);

ArvVar* arvv_insere(ArvVar* a, ArvVar* sa);

void arvv_imprime (ArvVar* a);

int arvv_pertence(ArvVar* a, char c);

void arvv_libera(ArvVar* a);

int arvv_altura(ArvVar* a);

int arvv_folhas(ArvVar* a);

#endif //ARVVAR_ARVVAR_H
