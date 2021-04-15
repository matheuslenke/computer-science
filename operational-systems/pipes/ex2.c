#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define SIZE 6
#define READ 0
#define WRITE 1

int main() {
    pid_t pid1, pid2;
    int status;
    int fd[2];
    char buffer[SIZE+1];
    struct rusage usage;
    pipe(fd);
    
    if((pid1=fork()) == 0) { // Child 1
        while(1) {
            read(fd[READ], buffer, SIZE);
            buffer[SIZE]='\0';
            write(fd[WRITE], "turnip", SIZE);
        }

    } else if( (pid2=fork()) == 0 ) { // Child 2
        while(1) {
            read(fd[READ], buffer, 6);
            buffer[6]='\0';
            write(fd[WRITE], "tomato", 6);
        }
    } else { // Parent  
        // write(fd[WRITE], "potato", 6);
        fprintf(stderr, "Parent: I wrote a potato!\n");
        sleep(3);
        read(fd[READ], buffer, 6);
        buffer[6]='\0';
        fprintf(stderr, "Parent: I got back a %s!\n", buffer);
        kill(pid1, SIGINT); waitpid(pid1, &status, NULL);
        kill(pid2, SIGINT); waitpid(pid2, &status, NULL);
    }
}