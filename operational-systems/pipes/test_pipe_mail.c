/* teste do envio de um mail usando tubos */
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    FILE *fp;
    int pid, pipefds[2];
    char *username, *getlogin();
    /* da o nome do usuario */
    if ((username = getlogin()) == NULL) {
        fprintf(stderr, "quem e voce?\n");
        exit(1);    }
     /* Cria um tubo. Isto deve ser feito antes do fork para que
      * o filho possa herdar esse tubo
      */
    if (pipe(pipefds) < 0) { perror("Error pipe");
        exit(1);    }
    if ((pid = fork()) < 0) {    perror("Error fork");
        exit(1); }
     /* Codigo do filho:
      * executa o comando mail e entao envia ao username
      * a mensagem contida no tubo */
    if (pid == 0) {
  /* redirige a stdout para o tubo; o comando executado em seguida tera
   como entrada (uma mensagem) a leitura do tubo */
        close(0);
        dup(pipefds[0]);
        close(pipefds[0]);
  /* fecha o lado de escrita do tubo, para poder ver a saida na tela */
        close(pipefds[1]);
        /* executa o comando mail */
        execl("/bin/mail", "mail", username, 0);
        perror("Error execl");
        exit(1);
}
    /* Codigo do pai:
     * escreve uma mensagem no tubo */
    close(pipefds[0]);
    fp = fdopen(pipefds[1], "w");
    fprintf(fp, "Hello from your program.\n");
    fclose(fp);
    /* Espera da morte do processo filho */
    while (wait((int *) 0) != pid) ;
    exit(0);
}
