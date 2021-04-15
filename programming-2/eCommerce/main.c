#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"

#define CRESCENTE 1
#define DECRESCENTE 0

int main() {
   tCatalogo* catalogo = inicializaCatalogo();
   catalogo = leCatalogo(catalogo);

   imprimeCatalogo(catalogo);

   tCatalogo* maisVendidos;
   maisVendidos = ordenaCatalogo(catalogo, comparaProdutoQuantidade, DECRESCENTE );
   printf("\n os mais vendidos são: \n");
   imprimeMaisVendidos(maisVendidos);

   tCatalogo* menosValioso;
   menosValioso = ordenaCatalogo(catalogo, comparaProdutoValor, CRESCENTE);
   printf("\n o menos valioso é: \n");
   imprimeMenosValioso(menosValioso);

   liberaCatalogoTodo(catalogo);
   //printf("terminou");
   return 0;
}