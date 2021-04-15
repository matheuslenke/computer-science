#include "aluno.h"

typedef struct tTurma {
    tAluno alunos[4];
    int quantidade_alunos;
}tTurma;


void lerTurma();

void apresentarTurma();

void obterNumeroAlunos();
void ordenarMatricula();
void ordenarIngresso();
void ordenarCR();
void ordenarNome();
void apresentarExcelentes();
void apresentarAniversariantes();
