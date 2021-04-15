#include <stdio.h>
#include "ponto.h"
#include <math.h>



void lerPonto(Tponto* ponto) {
    scanf("%d %d", &ponto->x, &ponto->y);
}

void apresentarPonto(Tponto* ponto) {
    printf("(%d,%d)", ponto->x, ponto->y);
}

float distancia (Tponto* p1, Tponto* p2) {
    return sqrt(pow(p1->x - p2-> x , 2)+pow(p1->y - p2->y , 2));
}
