/* Testa heranca dos descritores na chamada do fork().
 * O programa cria um tubo e depois faz um fork. O filho
 * vai se comunicar com o pai atraves desse tubo
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DATA "Testando envio de mensagem usando pipes"
int main() {
   int sockets[2], child;
   char buf[1024];
   /* criacao de um tubo */
   if ( pipe(sockets) == -1 ) {
          perror("Error opening stream socket pair") ;
          exit(10);
}
   /* criacao de um filho */
   if ( (child = fork()) == -1)
     perror ("Error fork") ;
   else if (child) {
/* Esta ainda e a execu ̧c~ao do pai. Ele l^e a mensagem do filho */
if ( close(sockets[1]) == -1) /* fecha o descritor nao utilizado */
          perror("Error close") ;
     if (read(sockets[0], buf, 1024) < 0 )
       perror("Error: reading message");
     printf("-->%s\n", buf);
     close(sockets[0]);
   } else {
     /* Esse e o filho. Ele escreve a mensagem para seu pai */
      if ( close(sockets[0]) == -1) /* fecha o descritor nao utilizado */
        perror("Error close") ;
      if (write(sockets[1], DATA, sizeof(DATA)) < 0 )
        perror("Error: writing message");
      close(sockets[1]);
   }
sleep(1);
exit(0); }
