#ifndef LISTA_H_
#define LISTA_H_


typedef struct tipoitem TipoItem;

typedef struct Celula TipoCelula;

typedef struct tipolista TipoLista;

TipoLista* InicializaLista();

int RetornaTamanhoLista(TipoLista* lista);

void Insere (TipoItem* pessoa, TipoLista* lista);

void EncontraSobrevivente (TipoLista* lista, int numero);

void Imprime (TipoLista* lista);

TipoLista* Libera (TipoLista* lista);

TipoItem *InicializaTipoItem(int numero);


#endif /* LISTA_H_ */