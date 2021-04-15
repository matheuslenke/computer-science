//
// Created by lenke on 24/09/2020.
//

#include "bst.h"
#include "pilha.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    Arv* dir;
    Arv* esq;
};

Arv* arv_criavazia(void) {
    Arv* a;
    a = (Arv*)malloc(sizeof(Arv));
    a->info = (int) NULL;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

int arv_vazia (Arv* a) {
    return (a==NULL) ? 1 : 0;
}

void arv_imprime_item(Arv* a) {
    printf("%d\n", a->info);
}

void arv_imprime(Arv* a) {
    printf("<");

    if (a != NULL) {
        if(a->esq != NULL) {
            arv_imprime(a->esq);
        }
        else {
            printf(" - ");
        }
        printf(" %d ", a->info);
        if(a->dir != NULL) {
            arv_imprime(a->dir);
        }
        else {
            printf(" - ");
        }
    }
    printf(">");
}

Arv* arv_insere (int info, Arv* a) {
    if(a == NULL) {
        a = arv_criavazia();
        a->info = info;
        return a;
    }

    if(info < a->info) {
        a->esq = arv_insere(info, a->esq);
        return a;
    }
    if(info > a->info) {
        a->dir = arv_insere(info, a->dir);
        return a;
    }
    if(info == a->info) {
        // printf("Não é possível inserir um valor igual\n");
        return a;
    }
}

Arv* arv_busca (Arv* a, int info ) {

}

Arv* retira(Arv *r, int v) {

}

int max2(int a, int b) {
    return (a>b) ? a : b;
}
int arv_altura (Arv* a) {
    if(arv_vazia(a)) {
        return -1;
    }
    else {
        return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));
    }

}

Arv* arv_libera (Arv* a) {
    if(a == NULL || (a->info ==  NULL && a->dir == NULL && a->esq == NULL)) {
        return NULL;
    }

    if(a->esq == NULL && a->dir == NULL) {
        free(a);
    }
    else {
        arv_libera(a->esq);
        arv_libera(a->dir);

    }
    return a;
}

void visita_arvore(Arv * a) {
    printf("%d\n", a->info);
}

void rec_preorder(Arv* a, void (*visita_arvore)(Arv*)) {
    if (a != NULL) {
        visita_arvore(a);
        if(a->esq != NULL) {
            rec_preorder(a->esq, visita_arvore);
        }
        if(a->dir != NULL) {
            rec_preorder(a->dir, visita_arvore);
        }
    }
}

void rec_inorder(Arv* a, void (*visita_arvore)(Arv*)) {
    if (a != NULL) {
        if(a->esq != NULL) {
            rec_inorder(a->esq, visita_arvore);
        }
        visita_arvore(a);
        if(a->dir != NULL) {
            rec_inorder(a->dir, visita_arvore);
        }
    }
}

void rec_postorder(Arv* a, void (*visita_arvore)(Arv*)) {
    if (a != NULL) {
        if(a->esq != NULL) {
            rec_postorder(a->esq, visita_arvore);
        }
        if(a->dir != NULL) {
            rec_postorder(a->dir, visita_arvore);
        }
        visita_arvore(a);
    }
}

void iterative_rec_preorder(Arv* a, void (*visita_arvore)(Arv*)) {
    if(a == NULL) return;

    Pilha* pilha = cria_pilha();
    push(a, pilha);
    while(eh_vazia(pilha) == -1) {
        Arv* arvoreRetirada = pop(pilha);
        visita_arvore(arvoreRetirada);
        if(arvoreRetirada->dir != NULL) {
            push(arvoreRetirada->dir, pilha);
        }
        if(arvoreRetirada->esq != NULL) {
            push(arvoreRetirada->esq, pilha);
        }
    }
}

void iterative_rec_inorder(Arv* a, void (*visita_arvore)(Arv*)) {
    if(a == NULL) return;
    Arv* node = a;
    Pilha* pilha = cria_pilha();

    while(eh_vazia(pilha) == -1 || node != NULL) {
        if (node != NULL) {
            push(node, pilha);
            node = node->esq;
        } else {
            node = pop(pilha);
            visita_arvore(node);
            node = node->dir;
        }
    }
}

void iterative_rec_postorder(Arv* a, void (*visita_arvore)(Arv*)) {
    if(a == NULL) return;
    Arv* node = a;
    Arv* lastNodeVisited = NULL;
    Arv* peekNode = NULL;

    Pilha* pilha = cria_pilha();

    while(eh_vazia(pilha) == -1 || node != NULL) {
        if (node != NULL) {
            push(node, pilha);
            node = node->esq;
        } else {
            peekNode = peek(pilha);
            if(peekNode->dir != NULL && lastNodeVisited != peekNode->dir) {
                node = peekNode->dir;
            } else {
                visita_arvore(peekNode);
                lastNodeVisited = pop(pilha);
            }
        }
    }
}

int arv_retorna_info(Arv* a) {
    return a->info;
}

void print_level_order(Arv* arv) {
    TipoLista* lista_de_nos = InicializaLista();
    Arv* a = arv;
    while(a) {
        arv_imprime_item(a);

        if(a->esq) {
            TipoItem* item = InicializaTipoItem(a->esq);
            Insere(item, lista_de_nos);
        }
        if(a->dir) {
            TipoItem* item = InicializaTipoItem(a->dir);
            Insere(item, lista_de_nos);
        }
//        Imprime(lista_de_nos);
        a = Retira(lista_de_nos);
     }
}