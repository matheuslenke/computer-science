/* teste de leitura num tubo fechado em escrita */
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, p_desc[2] ;
  char c ;
    pipe(p_desc) ; /* criacao do tubo */
    write(p_desc[1],"AB",2) ; /* escrita de duas letras no tubo */
    close(p_desc[1]) ;        /* fechamento do tubo em escrita */
    /* tentativa de leitura no tuno */
    for (i=1; i<=3; i++) {
      if ( (read(p_desc[0],&c,1) == 0) )
        printf("Tubo vazio\n") ;
      else printf("Valor lido: %c\n",c) ;
    }
    exit(0);
}