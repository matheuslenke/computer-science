#define LEN 11		/* defs.h */

#include <unistd.h>	/* son.c */
#include <stdlib.h>
#include "defs.h"
int
main(int argc, char *argv[]) {
  /* argv[1] - descritor de escrita; argv[2] - posicao do filho */
  char texto[LEN] = {' ',':',' ','B','o','m',' ','d','i','a','!'};
  texto[0] = 'A'+atoi(argv[2])-1;
  write( atoi(argv[1]), texto, LEN );
  _exit(0); 
}
