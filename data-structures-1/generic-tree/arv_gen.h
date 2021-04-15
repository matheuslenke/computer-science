//
// Created by Matheus Lenke on 08/12/19.
//

#ifndef ARVOREGEN_ARV_GEN_H
#define ARVOREGEN_ARV_GEN_H


typedef struct arvgen ArvGen;

ArvGen* arv_CriaVazia();

ArvGen* arv_cria(void* info, ArvGen* dir, ArvGen* esq);

int percorre(ArvGen* arv, int (*cb)(void*, void*), void* dado);

ArvGen* libera();

#endif //ARVOREGEN_ARV_GEN_H
