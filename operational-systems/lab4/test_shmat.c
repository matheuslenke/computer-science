/* test_shmat.c */
/* exemplo de utilizacao de shmat() 
* escrita num segmento de memoria compartilhada */
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define ADDKEY 123
#define MSG "Mensagem escrita na memoria comum"

int main() {
  int shmid ; /* identificador da memoria comum */
  int size = 1024 ;
  char *path="./" ;
  //char *path="./" ;
  unsigned int *endereco;
  char* stringlida;
  int flag = 0;
/* recuperacao do shmid */
  if ((shmid = shmget(ftok(path,ADDKEY), size,0)) == -1) {
        perror("Erro no shmget") ;
        exit(1) ; }
  printf("Sou o processo com pid: %d \n",getpid()) ;
  printf("Identificador do segmento recuperado: %d \n",shmid) ;
  printf("Este segmento e associado a chave unica: %d\n",ftok(path,ADDKEY)) ;
/* acoplamento do processo a zona de memoria */
  if ((endereco = shmat (shmid, 0, flag)) == (char*)-1){
       perror("acoplamento impossivel") ;
       exit (1) ; }
/* escrita na zona de memoria compartilhada */
  // printf("Endereço: %s\n", mem);
    printf("shmat.c\n");
    printf("\tcomo int==>%u\n", endereco) ;
   printf("\tcomo x==>%x\n", endereco) ;
   printf("\tendereço==>%u\n", &endereco) ;
  strcpy(endereco,MSG);
  // printf("\tstring ==>%s\n",mem);
  sleep(100);
  exit(0);
}

