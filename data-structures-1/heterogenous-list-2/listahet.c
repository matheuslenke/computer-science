//
// Created by 2019202297 on 04/10/19.
//

#include "listahet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int id;
    int ano;
    float valor;
};

struct listahet {
    Cliente* dono;
    void* item;
    struct listahet* prox;
    int id;

};


ListaHet* cria () {
    struct listahet* lista;
    lista = (struct listahet*)malloc(sizeof(listahet));
    lista = NULL;
    return lista;
}

Cliente* cria_cliente (char* nome, int id) {
    Cliente* cliente_criado;
    cliente_criado = (Cliente*)malloc(sizeof(Cliente));
    cliente_criado.nome = strdup(nome);
    cliente_criado.id = id;
    return cliente_criado;
}

Movel* cria_movel (int placa, int ano, float valor) {
    Movel* movel_criado;
    movel_criado = (Movel*)malloc(sizeof(Movel));
    movel_criado->placa = placa;
    movel_criado->ano = ano;
    movel_criado->valor = valor;
    movel_criado->id = _IMOVEL;
    return movel_criado;
}

Imovel* cria_imovel (int id, int ano, float valor) {
    Imovel* imovel_criado;
    imovel_criado = (Imovel*)malloc(sizeof(Imovel));
    imovel_criado->id = id;
    imovel_criado->valor = valor;
    imovel_criado->ano = ano;
    return imovel_criado;
}

ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item) {
    if(lista == NULL) {
        return lista;
    }

}

ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item) {

}

void imprime (ListaHet* lista) {
    ListaHet* p;
    for (p = lista; p!= NULL; p = p->prox) {
        if (p->id == _MOVEL) {
            Movel* m = p->item;
            printf("Cliente: %s Placa: %d, Ano: %d, Valor: %f",
                   p->dono->nome,
                   m->placa,
                   m->ano,
                   m->valor
        }
        else if (p->id == _IMOVEL) {
            Imovel* im = p->item;
            printf("Cliente: %s Placa: %d, Valor: %f",
                   p->dono->nome,
                   im->ano,
                   im->valor
        }
    }

}

ListaHet* retira_cliente (ListaHet* lista, int id_cliente) {

}

float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel) {

}
