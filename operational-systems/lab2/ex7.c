#include <stdio.h>
#include <unistd.h>     // For the syscall functions.
#include <sys/wait.h>   // For wait and related macros.
#include <errno.h>

int main() {
        pid_t pid1, pid2, pid3;
        pid1 = fork();
        if (pid1 < 0) { // Error occurred.
        fprintf(stderr, "Fork failed!\n");
        return 1;
        } else if (pid1 == 0) { // Child process.
            sleep(2);
            return 42;
        } else { // Parent process.
            pid2 = fork();

            if (pid2 < 0) {
                fprintf(stderr, "Fork failed!\n");
                return 1;
            } else if(pid2 == 0) {
                sleep(2);
                return 42;
            } else {
                pid3 = fork();
                if(pid3 < 0) {
                    fprintf(stderr, "Fork failed!\n");
                    return 1;
                } else if (pid3 == 0) {
                    sleep(2);
                    return 42;
                } else {
                    while(1) {
                        sleep(2);
                        int hasFinished = waitpid(-1, NULL, WNOHANG);
                        if(errno == ECHILD && hasFinished < 0) {
                                printf("Acabou");
                                break;
                        }
                        if(hasFinished > 0) {
                            printf("Meu filho pid=%d terminou.\n",
                            hasFinished);
                        } else {
                            
                            printf("Nenhum filho terminou\n");

                        }
                    }
                }
            }
           
    }
    
    return 0;
}
