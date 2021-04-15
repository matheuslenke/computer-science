#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h> 

int pid;
void resolveSIGUSR1Pai(int sig){
    int num;
    FILE* arq = fopen("dados.txt","r");
    fscanf(arq,"%d",&num);
    fclose(arq);
    fclose(fopen("dados.txt", "w"));
    kill(pid,SIGUSR1);
    printf("%d",num);
}

void resolveSIGUSR1Filho(int sig){
    FILE* arq = fopen("dados.txt","w");
    fprintf(arq,"%d",(int) time(NULL)/100);
    fclose(arq);
}


int main(){
    sigset_t set;
    pid =fork();
    int num;
    sigemptyset(&set);
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);
    sigprocmask(SIG_BLOCK, &sigset, NULL);
    if(pid == 0){
        struct sigaction sinal;
        sinal.sa_flags = SA_RESTART;
        sinal.sa_handler = &resolveSIGUSR1Filho;
        sigaction(SIGUSR1, &sinal, NULL);
        sigsuspend(&sigset);
    }
    else{
        struct sigaction sinal;
        sinal.sa_flags = SA_RESTART;
        sinal.sa_handler = &resolveSIGUSR1Pai;
        sigaction(SIGUSR1, &sinal, NULL);
        wait(NULL);
    }
}