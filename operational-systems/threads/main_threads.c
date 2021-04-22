#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine1()
{
    // printf("Process id %d\n", getpid());
    x += 5;
    sleep(2);
    printf("Value of x: %d\n", x);
}
void *routine2()
{
    // printf("Process id %d\n", getpid());
    sleep(2);
    printf("Value of x: %d\n", x);
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    printf("Começou!\n");

    if (pthread_create(&t1, NULL, &routine1, NULL)) {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine2, NULL)) {
        return 2;
    }
    if (pthread_join(t1, NULL)) {
        return 3;
    }
    if (pthread_join(t2, NULL)) {
        return 3;
    }

    printf("Terminou");
    sleep(4);
    return 0;
}