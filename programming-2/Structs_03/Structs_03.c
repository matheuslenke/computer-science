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



/* Recebe os racionais x e y e devolve o racional que representa a soma de x e y */
racional soma (racional x, racional y) {
	/* INSIRA SEU CODIGO AQUI */
   racional r;

   if((x.p < 0 || x.p > 0) && x.q < 0 && (y.p < 0 || y.p > 0) &&  y.q < 0) {
      
      x.p = -x.p;
      x.q = -x.q;
      y.p = -y.p;
      y.q = -y.q;
      
      if (x.q == y.q) {
         r.p = x.p + y.p;
         r.q = x.q;
      }
      else if (x.q != y.q) {
         r.q = x.q * y.q;
         r.p = (x.p * (r.q/x.q)) + (y.p * (r.q / y.q)); 
      }
   }
   else if( x.q > 0 &&  y.q < 0) {
      y.p = -y.p;
      y.q = -y.q;
      
      
      if (x.q == y.q) {
         r.p = x.p + y.p;
         r.q = x.q;
      }
      else if (x.q != y.q) {
         r.q = x.q * y.q;
         r.p = (x.p * (r.q/x.q)) + (y.p * (r.q / y.q)); 
      }
   }
   else if( x.q < 0 &&  y.q > 0) {
      
      x.p = -x.p;
      x.q = -x.q;
      
      if (x.q == y.q) {
         r.p = x.p + y.p;
         r.q = x.q;
      }
      else if (x.q != y.q) {
         r.q = x.q * y.q;
         r.p = (x.p * (r.q/x.q)) + (y.p * (r.q / y.q)); 
      }
   }
   
   else if( x.q > 0 &&  y.q > 0) {
      

      if (x.q == y.q) {
         r.p = x.p + y.p;
         r.q = x.q;
      }
      else if (x.q != y.q) {
         r.q = x.q * y.q;
         r.p = (x.p * (r.q/x.q)) + (y.p * (r.q / y.q)); 
      }
   }

   
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
   
   r = soma(x,y);
   printf("%d/%d \n", r.p, r.q);
   return 0;
}
