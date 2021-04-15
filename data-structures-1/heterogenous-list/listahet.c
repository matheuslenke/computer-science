//
// Created by 2019202297 on 04/10/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

#define _MOVEL 1
#define _IMOVEL 2

struct cliente {
    char* nome;
    int id;
};

struct movel {
    int placa;
    int ano;
    float valor;
    int id;
};

struct imovel {
    Cliente* dono;
    void* item;
    struct listahet* prox;
    int id;
};

struct listahet {
    Cliente* dono;
    void* item;
    struct listahet* prox;
    int id;

};


ListaHet* cria () {
    listahet* lista;
    lista = (listahet*)malloc(sizeof(listahet));
    lista = NULL;
    return lista;
}

Cliente* cria_cliente (char* nome, int id) {
    Cliente cliente_criado;
    cliente_criado.nome = strdup(nome);
    cliente_criado.id = id;
    return cliente_criado;
}

Movel* cria_movel (int placa, int ano, float valor) {

}

Imovel* cria_imovel (int id, int ano, float valor) {

}

ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item) {

}

ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item) {

}

void imprime (ListaHet* lista) {
    ListaHet* p;
    for (p = lista; p!= NULL; p = p->prox) {
        if (p->id == MOVEL) {
            Movel* m = p->item;
            printf("Cliente: %s Placa: %d, Ano: %d, Valor: %f",
                    p->dono,
                    m->placa,
                    m->ano,
                    m->valor
        }
        else if (p->id == MOVEL) {
            Movel* m = p->item;
            printf("Cliente: %s Placa: %d, Ano: %d, Valor: %f",
                   p->dono,
                   m->placa,
                   m->ano,
                   m->valor
        }
    }

}

ListaHet* retira_cliente (ListaHet* lista, int id_cliente) {

}

float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel) {

}
