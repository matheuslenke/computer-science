#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>     // For the syscall functions.
#include <sys/wait.h> 

pid_t pid;

void handle_siuser1(int sig) {
    if (sig == SIGUSR1) {
        FILE * file = fopen("dados.txt", "r");
        int numero;
        fscanf(file,"%d\n", &numero);
        printf("O número lido é: %d\n", numero);
        fclose(file);
        fclose(fopen("dados.txt", "w"));
        printf("%d", pid);
        if(pid > 0) {
            kill(pid, SIGUSR1);
        }
    }
}

void handle_siuser2(int sig) {
    if(sig == SIGUSR1) {
        FILE * file = fopen("dados.txt", "w");
        srand(time(NULL));
        int numero = (int)((rand() % 100) * 15 + 2);
        printf("Numero gerado: %d\n", numero);
        fprintf(file, "%d\n", numero);
        fclose(file);
    }
}

int main(int argc, char* argv[]) {
    // Mascara de bloqueio
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT); // Bloqueia SIGINT

    pid = fork(); // Fork a child process.
    if (pid < 0) { // Error occurred.
        fprintf(stderr, "Fork failed!\n");
        return 1;
    } else if (pid == 0) { // Child process.
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_siuser2;
        sa.sa_mask = sigset;
        // Setando o handler para a action SIGUSR1
        sigaction(SIGUSR1, &sa, NULL);
        // Setando a mascara para bloquear no Child
        sigsuspend(&sigset);
    } else { // Parent process.
        printf("[PARENT]: Waiting on SIGUSR1 signal.\n");
        int wstatus;
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_siuser1;
        // Setando o handler para a action SIGUSR1
        sigaction(SIGUSR1, &sa, NULL);
        // Setando mascara para bloquear no parent
        sigprocmask(SIG_BLOCK, &sigset, NULL);
        waitpid(pid, &wstatus, 0);
    }

    return 0;
}
