#include <stdio.h>
/* Estrutura para representar um ponto no espaço 2D */
typedef struct ponto {
   float x;
   float y;
} Ponto;

/* INSIRA SEU CODIGO AQUI, CASO DESEJE CRIAR ALGUMA FUNCAO AUXILIAR */



/* Funcao que indica se um dado ponto p estah localizado dentro ou fora de um retangulo.
   O retangulo eh definido por seus vertices inferior esquerdo v1 e superior direito v2.
   A funcao retorna 1 caso o ponto esteja localizado dentro do retangulo, e 0 caso contrario,
   sendo que os limites sao considerados como parte do retangulo */
int dentroRet (Ponto v1, Ponto v2, Ponto p) {
	
	/* INSIRA SEU CODIGO AQUI */
	if((p.x >= v1.x && p.x <= v2.x) && (p.y >= v1.y && p.y <= v2.y)){
      return 1;
   }
   else {
      return 0;
   }
	
	
}

int main(int argc, char const *argv[])
{
   Ponto v1;
   scanf("%f %f", &v1.x, &v1.y);
   Ponto v2;
   scanf("%f %f", &v2.x, &v2.y);
   Ponto p;
   scanf("%f %f", &p.x, &p.y);
   dentroRet(v1, v2, p);

   return 0;
}

