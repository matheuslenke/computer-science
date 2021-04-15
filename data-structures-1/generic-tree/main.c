#include <stdio.h>
#include "Arv_exp_gen.h"

int main() {
    // criando a arvore vazia
    ArvGen* arv = arv_CriaVazia();

    //Imprime a arvore (neste momento ainda vazia)
//    Imprime(arv);

    arv = CriaOperador('+',
                       CriaOperador('*',
                                    CriaOperador ('-',
                                                  CriaOperando (6), CriaOperando (3)),
                                    CriaOperador ('+',
                                                  CriaOperando (4), CriaOperando (1))),
                       CriaOperando (5));

    printf ("\nA arvore eh: ");
    //Imprime a arvore de expressoes
    arv_imprimeArvore(arv);

    return 0;
}