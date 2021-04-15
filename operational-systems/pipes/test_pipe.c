/* este programa  ́e equivalente ao comando shell ls|wc|wc */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int p_desc1[2] ;
int p_desc2[2] ;
void faire_ls()
{
     /* saida padrao redirecionada para o 1o. tubo */
     close (1) ;
     dup(p_desc1[1]) ;
     close(p_desc1[1]) ;
     /* fechamento dos descritores nao-utilizados */
     close(p_desc1[0]) ;
     close(p_desc2[1]) ;
     close(p_desc2[0]) ;
     /* executa o comando */
     execlp("ls","ls",0) ;
     perror("impossivel executar ls ") ;
}
void faire_wc1()
{
     /* redirecionamento da entrada padrao para o 1o. tubo*/
     close(0) ;
     dup(p_desc1[0]) ;
     close(p_desc1[0]) ;
     close(p_desc1[1]) ;
     /* redirecionamento da saida padrao para o 2o. tubo*/
     close(1) ;
     dup(p_desc2[1]) ;
     close(p_desc2[1]) ;
     close(p_desc2[0]) ;
     /* executa o comando */
     execlp("wc","wc",0) ;
     perror("impossivel executar o 1o. wc") ;
}
void faire_wc2()
{
     /* redirecionamento da entrada padrao para o 2o. tubo*/
     close (0) ;
     dup(p_desc2[0]) ;
     close(p_desc2[0]) ;
     /* fechamento dos descritores nao-utilizados */
     close(p_desc2[1]) ;
     close(p_desc1[1]) ;
     close(p_desc1[0]) ;
     /* executa o comando */
     execlp("wc","wc",0) ;
     perror("impossivel executar o 2o. wc") ;
}
int main() {
     /* criacao do primeiro tubo*/
     if (pipe(p_desc1) == -1)
          perror("Impossivel criar o 1o. tubo") ;
     /* criacao do segundo tubo */
     if (pipe(p_desc2) == -1)
          perror("impossivel criar o 1o. tubo") ;
     /* lancamento dos filhos */
     if (fork() == 0) faire_ls() ;
     if (fork() == 0) faire_wc1() ;
     if (fork() == 0) faire_wc2() ;
     exit(0);
}