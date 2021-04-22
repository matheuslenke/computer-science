#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int a[1000];
int finished = 0;
pthread_mutex_t mutex;
int counter = 0;

void* routine(void* arg) {
    int number = *(int*) arg;
    int sum = 0;
    for (int i = 0; i< 1000; i++) {
        if(a[i] == number) {
            sum++;
        }
    }
    pthread_mutex_lock(&mutex);
    if(finished == 0) {
        finished++;
        pthread_mutex_unlock(&mutex);
        // Se verdadeiro, retorna a soma aproveitando o ponteiro do arg
        *(int*)arg = sum;
        return arg;
    } else {
        pthread_mutex_unlock(&mutex);
        // Se falso, retorna -1 aproveitando o ponteiro do arg
        *(int*)arg = -1;
        return arg;
    }
}

void inicializa_array() {
    for(int i = 0; i < 1000; i++) {
        a[i] = (rand() % 100) + 1;
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[10];
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    int i;

    inicializa_array();

    // Inicializa as threads
    for(i = 0; i < 10; i++) {
        int* a = malloc(sizeof(int));
        *a = (rand() % 100) + 1;
        if (pthread_create(&th[i], NULL, &routine, (void*)a) != 0){
            perror("Failed to create thread\n");
            return 1;
        } 
    }
    // Aguarda o retorno das threads
    for(i = 0; i < 10; i++) {
        int* r;
        int sumReturned;
        if (pthread_join(th[i], (void*)&r) != 0){
            perror("Failed do Join Thread\n");
            return 3;
        }
        // Pega o valor da soma retornada e verifica se é o vencedor
        sumReturned = *r;
        if(sumReturned != -1) {
            printf("Thread [%d] de id %lu com contador: %d\n", i, th[i], sumReturned);
        }
        free(r);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}