#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    int index = *(int*) arg;
    int sum = 0;
    for (int i = 0; i< 5; i++) {
        sum+= primes[index + 1];
    }
    *(int*)arg = sum;
    return arg;
}

int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    for(i = 0; i < 2; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0){
            perror("Failed to create thread\n");
            return 1;
        }
       
      
    }
    int globalSum = 0;
    for(i = 0; i < 2; i++) {
        int* r;
        if (pthread_join(th[i], &r) != 0){
            perror("Failed do Join Thread\n");
            return 3;
        }
        globalSum += *r;
        printf("Sum received: %d\n", *r);
        free(r);
    }
    printf("Global sum: %d\n", globalSum);
    return 0;
}