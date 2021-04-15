#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void it_sigpipe()
{
     printf("Sinal SIGPIPE recebido \n") ;
}
int main() {
     int p_desc[2] ;
     signal(SIGPIPE,it_sigpipe) ;
     pipe(p_desc) ;
     close(p_desc[0]) ;  /* fechamento do tubo em leitura */
     if (write(p_desc[1],"0",1) == -1)
          perror("Error write") ;
     exit(0);
}