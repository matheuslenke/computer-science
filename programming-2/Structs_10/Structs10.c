#include <stdio.h>
#include<string.h>

struct aluno{
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
};
typedef struct aluno Aluno;

void imprime_aprovados (int n, Aluno* turma) {
    float media;
    for(int i = 0; i < n; i++) {
        media = (turma[i].p1 + turma[i].p2 + turma[i].p3) / 3;
        if(media >=7){
            printf("Mat: %s, Nome: %s, Turma: %c, MF: %.2f\n",
            turma[i].matricula,
            turma[i].nome,
            turma[i].turma,
            media
            );
        }

    }
}

 int main(int argc, char const *argv[])
 {


     Aluno* turma[1];
     int n = 1;

     strcpy(turma[0]->nome, "Lenke");
     strcpy(turma[0]->matricula, "2019");
     turma[0]->turma = '1';
     turma[0]-> p1 = 8;
     turma[0]-> p2 = 7;
     turma[0]-> p3 = 7;
     // strcpy(turma[1]->nome, "Lenke");
     // strcpy(turma[1]->matricula, "2119");
     // turma[1]->turma = '1';
     // turma[1]-> p1 = 7;
     // turma[1]-> p2 = 7;
     // turma[1]-> p3 = 7;
     //turma[0] = {"Lenke", "20192022", '1', 7, 7,}
     imprime_aprovados(n, *turma);
     return 0;
 }
