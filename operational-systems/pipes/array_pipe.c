#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// 2 Processes
// 1) Child process should generate random numbers and send them to the parent
// 2) Parent is going to sum all the numbers and print the result

int main (int argc, char* agrv[]) {
    int fd[2];
    if(pipe(fd) == -1) {
        printf("Error opening the pipe\n");
        return 2;
    }
    int pid = fork();
    if(pid == -1) {
        return 1;
    }

    if (pid == 0) {
        // Child Process
        close(fd[0]);
        int n, i;
        int arr[10];
        srand(time(NULL));
        n = rand() % 10 + 1;
        printf("Generated: ");
        for(i = 0; i < n; i++) {
            arr[i] = rand() % 11;
            printf("%d ", arr[i]);
        }
        printf("\n");
        if(write(fd[1], &n, sizeof(int)) < 0) {
            printf("Error writing on pipe\n");
            return 4;
        }
        if(write(fd[1], arr, sizeof(int) * n) < 0) {
            printf("Error writing on pipe\n");
            return 3;
        }
        close(fd[1]);
    } else  {
        // Parent Process
        close(fd[1]);
        int arr[10];
        int size;
        int sum = 0;
        if(read(fd[0], &size, sizeof(int)) < 0) {
            return 5;
        };
        if(read(fd[0], arr, sizeof(int) * size) < 0) {
            return 6;
        }
        printf("Array received with %d elements: \n", size);
        for(int i = 0; i < size; i++) {
            printf("%d | ", arr[i]);
            sum += arr[i];
        }
        printf("\nThe sum is: %d\n", sum);
        close(fd[0]);
    }
    return 0;
}