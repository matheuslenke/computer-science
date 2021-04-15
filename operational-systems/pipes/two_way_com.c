#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    // 5 => 5 * 4 = 20 => 20
    int p1[2];
    int p2[2];
    if (pipe(p1) == -1) { return 1; }
    if (pipe(p2) == -1) { return 1; }
    int pid = fork();
    if(pid == -1) { return 2; }
    if(pid == 0) {
        // Child process
        int x;
        close(p1[1]);
        close(p2[0]);
        if(read(p1[0], &x, sizeof(x)) == -1) { return 3; }
        printf("[CHILD]Received %d\n", x);
        x *= 4;
        if (write(p2[1], &x, sizeof(x)) == -1) { return 4; }
        printf("[CHILD]Wrote %d\n", x);
        close(p1[0]);
        close(p2[1]);
    } else {
        // Parent Process
        int x;
        srand(time(NULL));
        int y = rand() % 10;
        close(p1[0]);
        close(p2[1]);
        if(write(p1[1], &y, sizeof(y)) == -1) { return 5; }
        printf("[PARENT]Wrote %d\n", y);
        if (read(p2[0], &y, sizeof(y)) == -1) {return 6;}
        printf("[PARENT]Result is %d\n", y);
        wait(NULL);
        close(p1[1]);
        close(p2[0]);
    }
    return 0;
}