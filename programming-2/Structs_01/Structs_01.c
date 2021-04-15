#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.   
*/

typedef struct {
   int p, q;
} racional;

/* INSIRA SEU CODIGO AQUI, CASO DESEJE CRIAR ALGUMA FUNCAO AUXILIAR */



/* Recebe inteiros a e b e devolve o racional que representa a/b */
racional reduz (int a, int b) {
   racional r;
   r.p = a;
   r.q = b;
	/* INSIRA SEU CODIGO AQUI */

   if (a > 0 && b > 0 ) {
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }

   }
   if(a < 0 && b < 0) {
      a = -a;
      b = -b;
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
 
   }
   if(a > 0 && b < 0) {
      b = -b;
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
      a = -a;
   }
   if(a < 0 && b > 0) {
      a = -a;
      for(int i=1; i<=a && i<=b; i++) {
         if(a%i == 0 && b%i == 0) {
            a = a/i;
            b = b/i;
         }
      }
      a = -a;
   }

   r.p = a;
   r.q = b;
   return r;
}

int main(int argc, char const *argv[])
{
   racional r;
   scanf("%d", &r.p);
   scanf("%d", &r.q);
   r = reduz(r.p,r.q);
   printf("%d/%d \n", r.p, r.q);
   return 0;
}

