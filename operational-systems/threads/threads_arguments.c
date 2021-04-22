#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    sleep(1);
    int index = *(int*) arg;
    printf("%d ", primes[index]);
    free(arg);
    int value = rand() % 100;
    int* result = malloc(sizeof(int));
    *result = value;
    return (void*) result;
}

int main(int argc, char* argv[]) {
    pthread_t th[10];
    int *randomValues[10];
    srand(time(NULL));
    int i;
    for(i = 0; i < 10; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0){
            perror("Failed to create thread");
            return 1;
        }
       
      
    }
    for(i = 0; i < 10; i++) {
        if (pthread_join(th[i], (void**)&randomValues[i] ) != 0){
            perror("Failed do Join Thread");
            return 3;
        }
    }
    printf("\n");
    for(i = 0; i < 10; i++) {
        printf("Value received: %d\n", *randomValues[i]);
        free(randomValues[i]);
    }
    return 0;
}