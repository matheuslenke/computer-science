#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.
*/

typedef struct {
   int p, q;
} racional;

/* INSIRA SEU CODIGO AQUI, CASO PRECISE CRIAR ALGUMA FUNCAO AUXILIAR */



/* Recebe um racional x e devolve o racional −x */
racional neg (racional x) {
	
	/* INSIRA SEU CODIGO AQUI */
	int a = x.p;
   int b = x.q;

	if (a > 0 && b > 0 ) {
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
      x.p = -a;
      x.q = b;

    }
   else if (a < 0 && b < 0) {
      a = -a;
      b = -b;
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
      x.p = -a;
      x.q = b;

   }
   else if(a > 0 && b < 0) {
      b = -b;
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
      x.p = a;
      x.q = b;
      
   }
   else if(a < 0 && b > 0) {
      a = -a;
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
      x.p = a;
      x.q = b;
      
   }


   return x;
	
}

int main(int argc, char const *argv[])
{
   racional r;
   scanf("%d", &r.p);
   scanf("%d", &r.q);
   r = neg(r);
   printf("%d/%d \n", r.p, r.q);
   return 0;
}
