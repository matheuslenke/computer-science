#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


//  No arquivo aula1_2.c: Implemente funções em C para cada um dos problemas abaixo
// (todas as funções devem estar em um único arquivo aula1_2.c). Para cada uma das
// funções, implemente uma função main diferente (comente as outras para conseguir
// rodar):




/*2.1) Implemente uma função que calcule a área da superfície e o volume de uma esfera
de raio r. A área da superfície e o volume são dados, respectivamente, por
2 4pr e
4 / 3 3 pr . Essa função deve obedecer ao seguinte protótipo: void calc_esfera
(float r, float* area, float* volume); */


void calc_esfera(float r, float* area, float* volume) {
    float pi = 3.1416;

    *area = 4*(r*r)*M_PI;

    *volume = (4*(M_PI)*r*r*r)/3;
}



void main(void) {

    float r, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);
    printf("A área será: %f \n O volume será: %f \n", area, volume);


}







/* Exercicio 2.2) Implemente uma função que calcule o fatorial de um dado número. Protótipo: void
fatorial (int n, int* f); */

/*
void fatorial ( int n, int* f) {
    for(int i=1; i<=n; i++){
    *f =  (*f)*i;
    printf("%d \n", *f);

    }

}

void main(void) {
    int n, f;
    f=1;
    

    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &n);

    fatorial(n, &f);

    printf("O fatorial do numero é: %d \n ", f);


}
*/







/* 2.3) Implemente uma função que receba como parâmetro um vetor de números reais
(vet) de tamanho n e retorne quantos números negativos estão armazenados nesse
vetor. Essa função deve obedecer ao protótipo: int negativos (int n, float*
vet); */
/*
void negativos (int n, float* vet) {
    for (int i = 0; i<n; i++) {
        if ( vet[i] < 0) {
            *negativo++;
        }
    }

}

 void main(void) {
    float vet[10];
    int n = 10;
    int negativo = 0;

    printf("Digite 10 valores: \n");
    for (int i=0; i<10; i++) {
        printf("Digite o valor %d:", i);
        scanf("%f \n", &vet[i]);
    }
    negativo = negativos(n, vet, negativo);

    printf("Existem %d negativos neste vetor", negativo);
 
}
*/








/*2.4) Implemente uma função que receba como parâmetro um vetor de números
 inteiros (vet) de tamanho n e inverta a ordem dos elementos armazenados 
 nesse vetor. Essa função deve obedecer ao protótipo:
    void inverte (int n, int* vet);
 */

/*
void inverte(int n, int* vet) {
    int troca = 0;
    for(int i=0; i<n/2; i++) {
        troca = vet[i];
        vet[i] = vet[n-(1+i)];
        vet[n-(1+i)] = troca;
    }
}

void main(void) {
    int n = 10;
    int vet[n];
    //Gerando numeros aleatórios

    //Colocando semente da função Rand
      srand(time(NULL));
  
  for (int i=0; i < n; i++)
  {
    // gerando valores aleatórios na faixa de -10 a 10
    vet[i] = pow(-1, rand()%100)*(rand()%10);
    printf("%d \n",vet[i]);
  }

  //Chamando a função para inverter a ordem

 inverte(n, vet);

    printf("Valores do vetor invertido: \n");
    for (int i = 0; i<n; i++) {
        printf("%d \n", vet[i]);
    }

  
}
*/