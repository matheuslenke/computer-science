//
// Created by Matheus Lenke on 08/12/19.
//

#ifndef ARVOREGEN_ARV_EXP_GEN_H
#define ARVOREGEN_ARV_EXP_GEN_H

#include "arv_gen.h"

typedef struct arv Arv;

static int Imprime (void* info, void* dado);

ArvGen * CriaVazia(void);

ArvGen * CriaOperador(char c, Arv* esq, Arv* dir);

ArvGen * CriaOperando(int valor);

void arv_imprimeArvore(ArvGen* arv);

#endif //ARVOREGEN_ARV_EXP_GEN_H
