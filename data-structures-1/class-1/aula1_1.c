#include <stdio.h>
#include <stdlib.h>


int main (void) {

    int a, b, c, d;

    int *pa, *pb, *pc, *pd;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    printf("Digite um valor para a, b, c e d: ");
    scanf("%d %d %d %d", pa, pb, pc, pd);

    printf("Os valores de a, b, c e d são: %d %d %d %d", a,b,c,d);

    return 0;
}



