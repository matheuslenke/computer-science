#include <stdio.h>
/* Estrutura para representar um ponto no espaço 2D */
typedef struct vetor {
   float x;
   float y;
   float z;
} Vetor;

float dot (Vetor v1, Vetor v2) {
	/* INSIRA SEU CODIGO AQUI */
	float u;
    u = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    
	
	return u;
}

int main(int argc, char const *argv[])
{
   Vetor v1;
   scanf("%f %f", &v1.x, &v1.y);
   Vetor v2;
   scanf("%f %f", &v2.x, &v2.y);
   dot(v1, v2);

   return 0;
}

