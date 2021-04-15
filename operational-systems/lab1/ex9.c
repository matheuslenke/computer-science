//
// Created by lenke on 03/03/2021.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t c2, c1;
    c2 = 0;
    c1 = fork();
    sleep(10);
    if(c1 == 0) {
        c2 = fork();
        sleep(10);
    }
    fork();
    sleep(10);
    if (c2 > 0) {
        fork();
        sleep(10);
    }
    sleep(25);
    exit(0);
}
