               /* arquivo test_fifo.c */
/* este programa mostra a criacao e destruicao de tubos
 * com nome
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
     printf("Vou criar um tubo de nome ’fifo1’\n") ;
     printf("Vou criar um tubo de nome ’fifo2’\n") ;
     if (mknod("fifo1",S_IFIFO | O_RDWR, 0) == -1) {
          perror("Criacao de fifo1 impossivel") ;
exit(1) ; }
     if (mknod("fifo2",S_IFIFO | O_RDWR, 0) == -1) {
          perror("Criacao de fifo2 impossivel") ;
          exit(1) ;
     }
     sleep(10) ;
     printf("Vou apagar o tubo de nome ’fifo1’\n") ;
     unlink("fifo1") ;
     exit(0);
}