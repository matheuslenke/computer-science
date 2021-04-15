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



/* Recebe os racionais x e y e devolve o racional que representa o quociente de x por y */
racional quoci (racional x, racional y) {

	/* INSIRA SEU CODIGO AQUI */
racional r;
   r.p = x.p * y.q;
   r.q = x.q * y.p;
	 // SIMPLIFICANDO

   if (r.p > 0 && r.q > 0 ) {
      for(int i=1; i<=r.p && i<=r.q; i++) {
         if(r.p%i == 0 && r.q%i == 0) {
      do {
               r.p = r.p/i;
               r.q = r.q/i;
          } while (r.p%i == 0 && r.q%i == 0 && i!=1);
   
  }    }

   }
   if(r.p < 0 && r.q < 0) {
      r.p = -r.p;
      r.q = -r.q;
      for(int i=1; i<=r.p && i<=r.q; i++) {
         if(r.p%i == 0 && r.q%i == 0) {
            do {
                  r.p = r.p/i;
                  r.q = r.q/i;
            } while (r.p%i == 0 && r.q%i == 0 && i!=1);
         }
   }
 
   }
   if(r.p > 0 && r.q < 0) {
      r.q = -r.q;
      for(int i=1; i<=r.p && i<=r.q; i++) {
         if(r.p%i == 0 && r.q%i == 0) {
            do {
                  r.p = r.p/i;
                  r.q = r.q/i;
            } while (r.p%i == 0 && r.q%i == 0 && i!=1);
         }
   }
      r.p = -r.p;
   }
   if(r.p < 0 && r.q > 0) {
      r.p = -r.p;
      for(int i=1; i<=r.p && i<=r.q; i++) {
         if(r.p%i == 0 && r.q%i == 0) {
            do {
                  r.p = r.p/i;
                  r.q = r.q/i;
            } while (r.p%i == 0 && r.q%i == 0 && i!=1);
         }
      }
      r.p = -r.p;
   }
   if(r.p == 0) {
      r.q = 1;
   }
   if(r.q == 0){
      r.p = 0;
   }

   return r;
	
		
}


int main(int argc, char const *argv[])
{
   racional x, y, r;
   scanf("%d", &x.p);
   scanf("%d", &x.q);
   scanf("%d", &y.p);
   scanf("%d", &y.q);
   
   r = quoci (x,y);
   printf("%d/%d \n", r.p, r.q);
   return 0;
}

	
		

